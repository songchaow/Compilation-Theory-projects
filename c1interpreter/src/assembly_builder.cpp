
#include "assembly_builder.h"

#include <vector>
#include <string>

using namespace llvm;
using namespace c1_recognizer::syntax_tree;

void assembly_builder::visit(assembly &node)
{
    // a module is allocated
    // module.reset(new Module(node.source_name, context));
    for(auto&& def:node.global_defs)
        def.get()->accept(*this);
}

void assembly_builder::visit(func_def_syntax &node)
{
    // create void function type, with no params, as specified in C1 languagen
    auto ftype = FunctionType::get(Type::getVoidTy(context),false);
    auto func = Function::Create(ftype,GlobalValue::LinkageTypes::ExternalLinkage,node.name,module.get());
    // one function in C1 has only one block ({...})
    // note that it's possible that one function has more than one LLVM block
    current_function = func;
    in_global = false;
    node.body.get()->accept(*this);
    builder.CreateRetVoid();
    builder.ClearInsertionPoint();
    // examine whether a function with same name has been declared before
    if(functions.count(node.name))
    {
        error_flag = true;
        err.error(node.line,node.pos,"Function \""+node.name+"\" has been defined before.");
    }
    else
        functions[node.name] = func;
    
    in_global = true;
    
    
}

void assembly_builder::visit(cond_syntax &node)
{
    lval_as_rval = true;
    node.lhs.get()->accept(*this);
    auto lhs = value_result;
    node.rhs.get()->accept(*this);
    auto rhs = value_result;
    // generate instructions to compare the two operands,
    // and store the bool result
    switch(node.op)
    {
        case relop::equal:
            value_result = builder.CreateICmpEQ(lhs,rhs);break;
        case relop::greater:
            value_result = builder.CreateICmpSGT(lhs,rhs);break;
        case relop::greater_equal:
            value_result = builder.CreateICmpSGE(lhs,rhs);break;
        case relop::less:
            value_result = builder.CreateICmpSLT(lhs,rhs);break;
        case relop::less_equal:
            value_result = builder.CreateICmpSLE(lhs,rhs);break;
        case relop::non_equal:
            value_result = builder.CreateICmpNE(lhs,rhs);break;
        
    }
}

void assembly_builder::visit(binop_expr_syntax &node)
{
    // generate instructions calculating the 2 operands
    // the `constexpr_expected` flag is from the visit function outside
    lval_as_rval = true;
    int lhs_num,rhs_num;
    node.lhs.get()->accept(*this);
    auto lhs = value_result;
    if(constexpr_expected)
        lhs_num = const_result;
    node.rhs.get()->accept(*this);
    auto rhs = value_result;
    if(constexpr_expected)
        rhs_num = const_result;
    if(constexpr_expected)
    {
        switch(node.op)
        {
            case binop::plus:
                const_result = lhs_num+rhs_num;break;
            case binop::minus:
                const_result = lhs_num-rhs_num;break;
            case binop::divide:
                if(rhs_num==0)
                {
                    error_flag = true;
                    err.error(node.line,node.pos,"Division by zero found in constant expression.");
                    const_result = 0;
                }
                else const_result = lhs_num/rhs_num;break;
            case binop::modulo:
                const_result = lhs_num%rhs_num;break;
            case binop::multiply:
                const_result = lhs_num*rhs_num;break;
        }
    }
    else
    {
        // generate instructions performing the calculation
        switch(node.op)
        {
            case binop::plus:
                value_result = builder.CreateAdd(lhs,rhs);break;
            case binop::minus:
                value_result = builder.CreateSub(lhs,rhs);break;
            case binop::divide:
                value_result = builder.CreateSDiv(lhs,rhs);break;
            case binop::modulo:
                value_result = builder.CreateURem(lhs,rhs);break;
            case binop::multiply:
                value_result = builder.CreateMul(lhs,rhs);break;
        }
    }

}

void assembly_builder::visit(unaryop_expr_syntax &node)
{   // the `constexpr_expected` flag is from the visit function outside
    lval_as_rval = true;
    node.rhs.get()->accept(*this);
    int rhs_num;
    auto rhs = value_result;
    if(constexpr_expected)
    {
        if(node.op==unaryop::minus)
            const_result = -const_result;
    }
    else if(node.op==unaryop::minus)
        value_result = builder.CreateSub(ConstantInt::get(context,APInt(32,0,true)),rhs);
}

void assembly_builder::visit(lval_syntax &node)
{
    /* 
        although it's `lval_syntax` that we are visiting, it may also serve as right_value,
    so the flag `lval_as_rval` is needed.
    possible errors are listed below:
        1. the flag `constexpr_expected` is set.
        2. no such variable has been declared
        3. the variable is a constant.
        4. the variable has no array_index(ie, `[]`) according to the node. But the llvm info shows it's an array. same as 2.
        the array's identifier can not be modified.
        5. the variable has an array_index(ie, `[]`) according to the node. But the llvm info shows it's not an array. */
    auto var = lookup_variable(node.name);
    auto val_ptr = std::get<0>(var); // it's ADDRESS of the particular variable.
    auto is_const = std::get<1>(var);
    auto is_array = std::get<2>(var);

    if(constexpr_expected)
    {
        error_flag = true;
        err.error(node.line,node.pos,"Lvalue \""+node.name+"\" cannot be used as constant expression.");
        value_result = ConstantInt::get(context,APInt(32,0,true));
        return;
    }
    if(!val_ptr)
    {
        error_flag = true; // it hasn't been declared before
        err.error(node.line,node.pos,"Undeclared variable \""+node.name+"\".");
        value_result = ConstantInt::get(context,APInt(32,0,true));
        return;
    }

    else
    {
        if(is_const)
        {
            error_flag = true;
            err.error(node.line,node.pos,"Constant \""+node.name+"\" cannot be Lvalue.");
            value_result = ConstantInt::get(context,APInt(32,0,true));
        return;
        }
        else if(is_array)
        {
            if(!node.array_index) //eg, visiting a, not a[...]
            {
                if(!lval_as_rval)
                {
                    error_flag = true;
                    err.error(node.line,node.pos,"Array identifier \""+node.name+"\" cannot be Lvalue.");
                    value_result = ConstantInt::get(context,APInt(32,0,true));
                    return;
                }
                else
                {
                    value_result = val_ptr;
                    err.warn(node.line,node.pos,"The address of array \""+node.name+"\" is fetched, which is usually meaningless in C1.");
                }
            }
            else
            {
                // calculate the index expr
                // note that the index must be fetched as a right value, but `lval_as_rval` for the array element may be false.
                // so a backup should be made.
                auto lval_as_rval_backup = lval_as_rval;
                lval_as_rval = true;
                node.array_index.get()->accept(*this);
                lval_as_rval = lval_as_rval_backup;

                // examine whether the index is legal
                if(const_result<0)
                {
                    error_flag = true;
                    err.error(node.line,node.pos,"Referencing array element \""+node.name+"\" with negative index.");
                }

                //calculate address of the element
                /* auto actual_index = builder.CreateMul(value_result,ConstantInt::get(context,APInt(4,32,true)));
                value_result = builder.CreateAdd(val_ptr,actual_index);  */
                std::vector<Value*> index_list;
                //index_list.push_back(ConstantInt::get(context,APInt(32,0,true)));
                index_list.push_back(value_result);
                auto element_ptr = builder.CreateGEP(Type::getInt32Ty(context),val_ptr,index_list);
                if(lval_as_rval)
                    value_result = builder.CreateLoad(element_ptr);
                else
                    value_result = element_ptr;
            }
        }
        else // a single element
        {
            if(node.array_index)
            {
                error_flag = true;
                err.error(node.line,node.pos,"Variable \""+node.name+"\" with `int` type can not be used as an array identifier.");
                value_result = ConstantInt::get(context,APInt(32,0,true));
                return;
            }
            else if(lval_as_rval)
                value_result = builder.CreateLoad(val_ptr);
            else
                value_result = val_ptr;
        }

    }
}

void assembly_builder::visit(literal_syntax &node)
{
    if(constexpr_expected)
        const_result = node.number;
    else
        value_result = ConstantInt::get(context,APInt(32,node.number,true));
}

void assembly_builder::visit(var_def_stmt_syntax &node)
{
    if(in_global)
    {
        auto is_array = (bool)node.array_length;
        GlobalVariable* gval;
        if(is_array)
        {
        // we have to build the type of array
        // first calculate the length statically
            constexpr_expected = true;
            node.array_length.get()->accept(*this);
            constexpr_expected = false;
        // check if the index is legal
            if(const_result<0)
            {
                error_flag = true;
                err.error(node.line,node.pos,"Index of array \""+node.name+"\" cannot be negative.");
            }
            
            if(const_result<node.initializers.size())
            {
                error_flag = true;
                err.error(node.line,node.pos,"Initializers of Array \""+node.name+"\" are bigger than its size.");
                return;
            }

            auto array_ty = ArrayType::get(Type::getInt32Ty(context),const_result);
            // build initializers
            std::vector<Constant*> init_values;
            constexpr_expected = true;
            for(auto&& value_ptr:node.initializers)
            {   // calculate initial values statically
                value_ptr->accept(*this);
                init_values.push_back(ConstantInt::get(context,APInt(32,const_result,true)));
            }
            constexpr_expected = false;
            auto array_init = ConstantArray::get(array_ty,init_values);
            gval = new GlobalVariable(*(module.get()),Type::getInt32Ty(context),node.is_constant,GlobalValue::LinkageTypes::ExternalLinkage,array_init,node.name);

        }
        else // single element
        {
            if(node.initializers.size()>=1)
            {
                // calculate initial values statically
                constexpr_expected = true;
                node.initializers[0]->accept(*this);
                constexpr_expected = false;
                auto integer_init = ConstantInt::get(Type::getInt32Ty(context),const_result);
                gval = new GlobalVariable(*(module.get()),Type::getInt32Ty(context),node.is_constant,GlobalValue::LinkageTypes::ExternalLinkage,integer_init,node.name);
            }
            else
            {
                auto integer_init = ConstantInt::get(Type::getInt32Ty(context),0);
                gval = new GlobalVariable(*(module.get()),Type::getInt32Ty(context),node.is_constant,GlobalValue::LinkageTypes::ExternalLinkage,integer_init,node.name);
            }
        }
        if(!declare_variable(node.name,gval,node.is_constant,is_array))
        {
            error_flag = true;
            err.error(node.line,node.pos,"Identifier \""+node.name+"\" has already been declared before.");
        }
    }
    else
    {
        
        bool is_array=(bool)node.array_length;
        if(is_array)
        {
            constexpr_expected = true;
            node.array_length.get()->accept(*this);
            constexpr_expected = false;
            if(const_result<node.initializers.size())
            {
                error_flag = true;
                err.error(node.line,node.pos,"Declaring array \""+node.name+"\" with longer initializers than its length.");
            }
        }
        
        auto var_ptr = builder.CreateAlloca(Type::getInt32Ty(context),is_array?ConstantInt::get(context,APInt(32,const_result,true)):nullptr);
        if(!declare_variable(node.name,var_ptr,node.is_constant,is_array))
        {
            error_flag = true;
            err.error(node.line,node.pos,"Identifier \""+node.name+"\" has already been declared before.");
        }
        if(is_array)
        {
            // assign values in initializers
            std::vector<Value*> index_list;
            int index=0;
            //index_list.push_back(ConstantInt::get(context,APInt(32,0,true)));
            index_list.push_back(ConstantInt::get(context,APInt(32,index,true)));
            for(auto&& value_ptr:node.initializers)
            {
                index_list[0] = ConstantInt::get(context,APInt(32,index,true));
                auto elem_ptr = builder.CreateGEP(Type::getInt32Ty(context),var_ptr,ArrayRef<Value*>(index_list));
                // calculate the current value in initializers
                lval_as_rval = true;
                value_ptr.get()->accept(*this);
                builder.CreateStore(value_result,elem_ptr);
                index++;
            }
        }
        else //single element
        {
            lval_as_rval = true;
            if(node.initializers.size()>=1)
            {
                node.initializers[0]->accept(*this);
                builder.CreateStore(value_result,var_ptr);
            }
        }
        
    }
}

void assembly_builder::visit(assign_stmt_syntax &node)
{
    // resolve the lvalue
    lval_as_rval = false;
    node.target->accept(*this);
    auto target = value_result;
    if(!value_result)
    {
        error_flag = true;
        err.error(node.line,node.pos,"Unable to resolve identifier \""+node.target->name+"\".");
        return;
    }
    // calculate the value to be assigned
    lval_as_rval = true;
    node.value->accept(*this);
    builder.CreateStore(value_result,target);
}

void assembly_builder::visit(func_call_stmt_syntax &node)
{
    if(functions.count(node.name))
    {
        auto func = functions[node.name];
        builder.CreateCall(func);
    }
    else
    {
        error_flag = true;
        err.error(node.line,node.pos,"Undefined function \""+node.name+"\".");
    }
}

void assembly_builder::visit(block_syntax &node)
{
    enter_scope();
    // It's not neccessarily needed to create an LLVM block for every block_syntax 
    // But if at present,  no block has been created since the function is created,
    // we will create one here.
    if(!builder.GetInsertBlock())
    {
        auto func_block = BasicBlock::Create(context,"entry",current_function);
        bb_count++;
        builder.SetInsertPoint(func_block);
    }
    for(auto&& stmt:node.body)
    {
        stmt.get()->accept(*this);
    }
    exit_scope();
}

void assembly_builder::visit(if_stmt_syntax &node)
{
    // three blocks must be created. we use bb_count to uniquely identify them
    auto then_block = BasicBlock::Create(context,"then"+std::to_string(bb_count),current_function);
    auto cont_block = BasicBlock::Create(context,"continue"+std::to_string(bb_count),current_function);
    bb_count+=3;
    // generate code judging whether condition is met
    node.pred.get()->accept(*this);
    // add branch instructions for original brick(this cannot be done in visit function for cond_syntax)
    if(node.else_body)
    {
        auto else_block = BasicBlock::Create(context,"else"+std::to_string(bb_count),current_function);    
        builder.CreateCondBr(value_result,then_block,else_block);
        builder.SetInsertPoint(else_block);
        node.else_body->accept(*this);
        builder.CreateBr(cont_block);
    }
    else
        builder.CreateCondBr(value_result,then_block,cont_block);
    builder.SetInsertPoint(then_block);
    node.then_body.get()->accept(*this);
    builder.CreateBr(cont_block);
    // these two blocks won't have more contents
    builder.SetInsertPoint(cont_block);
    
}

void assembly_builder::visit(while_stmt_syntax &node)
{
    // two blocks must be created like above.
    auto judge_block = BasicBlock::Create(context,"judge"+std::to_string(bb_count),current_function);
    auto loop_block = BasicBlock::Create(context,"loop"+std::to_string(bb_count),current_function);
    auto cont_block = BasicBlock::Create(context,"continue"+std::to_string(bb_count),current_function);
    bb_count+=2;
    // first we must jump to judge
    builder.CreateBr(judge_block);
    // generate code judging whether condition is met
    builder.SetInsertPoint(judge_block);
    node.pred.get()->accept(*this);
    // add branch instructions here
    builder.CreateCondBr(value_result,loop_block,cont_block);

    builder.SetInsertPoint(loop_block);
    node.body.get()->accept(*this);
    builder.CreateBr(judge_block);
    
    builder.SetInsertPoint(cont_block);
}

void assembly_builder::visit(empty_stmt_syntax &node)
{
    ;
}

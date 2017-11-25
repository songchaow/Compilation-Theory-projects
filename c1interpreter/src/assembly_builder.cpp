
#include "assembly_builder.h"

#include <vector>
#include <string>

using namespace llvm;
using namespace c1_recognizer::syntax_tree;

void assembly_builder::visit(assembly &node)
{
    // a module is allocated
    module.reset(new Module(node.source_name, context));
    for(auto&& def:node.global_defs)
        def.get()->accept(*this);
}

void assembly_builder::visit(func_def_syntax &node)
{
    // create void function type, with no params, as specified in C1 language
    auto ftype = FunctionType::get(Type::getVoidTy(context),ArrayRef<Type*>(),false);
    auto func = Function::Create(ftype,GlobalValue::LinkageTypes::ExternalLinkage,node.name,module.get());
    // one function in C1 has only one block
    // note that it's possible that one function has more than one LLVM block
    current_function = func;
    node.body.get()->accept(*this);
    builder.CreateRetVoid();
    
}

void assembly_builder::visit(cond_syntax &node)
{
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
    node.lhs.get()->accept(*this);
    auto lhs = value_result;
    node.rhs.get()->accept(*this);
    auto rhs = value_result;
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

void assembly_builder::visit(unaryop_expr_syntax &node)
{
    node.rhs.get()->accept(*this);
    auto rhs = value_result;
    if(node.op==unaryop::minus)
        value_result = builder.CreateSub(ConstantInt::get(context,APInt(0,32,true)),rhs);
}

void assembly_builder::visit(lval_syntax &node)
{
}

void assembly_builder::visit(literal_syntax &node)
{
    value_result = ConstantInt::get(context,APInt(1,32,true));
}

void assembly_builder::visit(var_def_stmt_syntax &node)
{
}

void assembly_builder::visit(assign_stmt_syntax &node)
{
}

void assembly_builder::visit(func_call_stmt_syntax &node)
{
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
    auto else_block = BasicBlock::Create(context,"else"+std::to_string(bb_count),current_function);
    auto cont_block = BasicBlock::Create(context,"continue"+std::to_string(bb_count),current_function);
    bb_count+=3;
    // generate code judging whether condition is met
    node.pred.get()->accept(*this);
    // add branch instructions for original brick(this cannot be done in visit function for cond_syntax)
    builder.CreateCondBr(value_result,then_block,else_block);
    builder.SetInsertPoint(then_block);
    node.then_body.get()->accept(*this);
    builder.CreateBr(cont_block);

    builder.SetInsertPoint(else_block);
    node.else_body.get()->accept(*this);
    builder.CreateBr(cont_block);
    // these two blocks won't have more contents
    builder.SetInsertPoint(cont_block);
    
}

void assembly_builder::visit(while_stmt_syntax &node)
{
}

void assembly_builder::visit(empty_stmt_syntax &node)
{
}


#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>

#include <memory>
#include <array>
#define INT_LEN 32

using namespace llvm;

int main()
{
    LLVMContext context;
    IRBuilder<> builder(context);

    auto module = new Module("gen_fib", context);
    // get function type for int(int)
    std::vector<Type*> params(1,Type::getInt32Ty(context));
    
    
    auto fib_ftype = FunctionType::get(Type::getInt32Ty(context),params,false);
    
    auto func_fib = Function::Create(fib_ftype,GlobalValue::LinkageTypes::ExternalLinkage,"fib",module);
    auto entry_block = BasicBlock::Create(context, "entry", func_fib);
    auto to_return_block = BasicBlock::Create(context, "to_return", func_fib);
    auto continue_block = BasicBlock::Create(context, "continue", func_fib);
    auto to_return2_block = BasicBlock::Create(context, "to_return2", func_fib);
    auto recurse_block = BasicBlock::Create(context, "recurse", func_fib);
    auto return_block = BasicBlock::Create(context, "return", func_fib);
    // TODO: add more blocks here

    //----- inside fib
    builder.SetInsertPoint(entry_block);
    //----- block entry
    auto retval = builder.CreateAlloca(Type::getInt32Ty(context),nullptr,"retval");
    auto n_addr = builder.CreateAlloca(Type::getInt32Ty(context),nullptr,"n.addr");
    builder.CreateStore(&*(module->getFunction(StringRef("fib"))->arg_begin()), n_addr);
    auto n_value = builder.CreateLoad(n_addr);
    //generate branch stmts
    auto cmp = builder.CreateICmpEQ(n_value,ConstantInt::get(context,APInt(0,32,true)),"cmp");
    builder.CreateCondBr(cmp,to_return_block,continue_block);
    //----- block to_return
    builder.SetInsertPoint(to_return_block);
    builder.CreateStore(ConstantInt::get(context,APInt(0,32,true)),retval);
    builder.CreateBr(return_block);
    //----- block continue
    builder.SetInsertPoint(continue_block);
    n_value = builder.CreateLoad(n_addr);
    cmp = builder.CreateICmpEQ(n_value,ConstantInt::get(context,APInt(1,32,true)),"cmp1");
    builder.CreateCondBr(cmp,to_return2_block,recurse_block);
    //----- block to_return2
    builder.SetInsertPoint(to_return2_block);
    builder.CreateStore(ConstantInt::get(context,APInt(1,32,true)),retval);
    builder.CreateBr(return_block);
    //----- block recurse
    builder.SetInsertPoint(recurse_block);
    n_value = builder.CreateLoad(n_addr);
    auto sub = builder.CreateSub(n_value,ConstantInt::get(context,APInt(1,32,true)),"sub",false,true);
    std::vector<Value*> args;
    args.push_back(sub);
    auto call = builder.CreateCall(func_fib,args);
    n_value = builder.CreateLoad(n_addr);
    auto sub4 = builder.CreateSub(n_value,ConstantInt::get(context,APInt(2,32,true)),"sub4",false,true);
    args.pop_back();
    args.push_back(sub4);
    auto call5 = builder.CreateCall(func_fib,args);
    auto add = builder.CreateAdd(call,call5,"add",false,true);
    builder.CreateStore(add,retval);
    builder.CreateBr(return_block);
    //-----block return
    builder.SetInsertPoint(return_block);
    auto return_value = builder.CreateLoad(retval);
    builder.CreateRet(return_value);

    auto func_main = Function::Create(FunctionType::get(Type::getInt32Ty(context), std::vector<Type *>(), false),
    GlobalValue::LinkageTypes::ExternalLinkage,
    "main", module);
    
    auto main_entry_block = BasicBlock::Create(context, "entry", func_main);
    auto for_cond_block = BasicBlock::Create(context, "for.cond", func_main);
    auto for_body_block = BasicBlock::Create(context, "for.body", func_main);
    auto for_inc_block = BasicBlock::Create(context, "for.inc", func_main);
    auto for_end_block = BasicBlock::Create(context, "for.end", func_main);
    //----- block entry
    builder.SetInsertPoint(main_entry_block);
    retval = builder.CreateAlloca(Type::getInt32Ty(context),nullptr,"retval");
    auto x = builder.CreateAlloca(Type::getInt32Ty(context),nullptr,"x");
    auto i = builder.CreateAlloca(Type::getInt32Ty(context),nullptr,"i");
    builder.CreateStore(ConstantInt::get(context,APInt(0,32,true)),retval);
    builder.CreateStore(ConstantInt::get(context,APInt(0,32,true)),x);
    builder.CreateStore(ConstantInt::get(context,APInt(0,32,true)),i);
    builder.CreateBr(for_cond_block);
    //----- block for.cond
    
    builder.SetInsertPoint(for_cond_block);
    auto i_value = builder.CreateLoad(i);
    cmp = builder.CreateICmpSLT(i_value,ConstantInt::get(context,APInt(10,32,true)),"cmp");
    builder.CreateCondBr(cmp,for_body_block,for_end_block);
    //----- block for.body
    builder.SetInsertPoint(for_body_block);
    i_value = builder.CreateLoad(i);
    args.clear();
    args.push_back(i_value);
    call = builder.CreateCall(func_fib,args,"call");
    auto x_value = builder.CreateLoad(x);
    add = builder.CreateAdd(x,call,"add",false,true);
    builder.CreateStore(add,x);
    //----- block for.inc
    builder.SetInsertPoint(for_inc_block);
    i_value = builder.CreateLoad(i);
    auto inc = builder.CreateAdd(i_value,ConstantInt::get(context,APInt(1,32,true)),"inc",false,true);
    builder.CreateStore(inc,i);
    //----- block for.end
    builder.SetInsertPoint(for_end_block);
    x_value = builder.CreateLoad(x);
    builder.CreateRet(x_value);
    builder.ClearInsertionPoint();
    //----- end main

    module->print(outs(), nullptr);
    delete module;
    return 0;
}

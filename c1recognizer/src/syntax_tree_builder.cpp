
#include "syntax_tree_builder.h"
#include <memory>

using namespace c1_recognizer;
using namespace c1_recognizer::syntax_tree;

syntax_tree_builder::syntax_tree_builder(error_reporter &_err) : err(_err) {}

antlrcpp::Any syntax_tree_builder::visitCompilationUnit(C1Parser::CompilationUnitContext *ctx)
{
    // funcdef -> global_def_syntax::func_def_syntax
    // decl ( constdecl or vardecl ) -> var_def_stmt_syntax (also used for stmt)
    // return a vector of nodes
    ptr_list<global_def_syntax> global_defs;
    auto raw_defs = ctx->children;
    for(auto &item : raw_defs)
    {
        if(antlrcpp::is<C1Parser::FuncdefContext*>(item))
        // there is only one functin's definition
            global_defs.push_back(visit(item).as<global_def_syntax*>());
        else if(antlrcpp::is<C1Parser::DeclContext>)
        // it will return a vector containing several var_def_syntaxes
        // we add them to global_defs
        {
            auto var_defs = visit(item).as<ptr_list<global_def_syntax>>();
            for(auto &var_def : vardefs)
                global_defs.push_back(var_def);
        }
    }
    return static_cast<ptr_list<global_def_syntax>> global_defs;
}

antlrcpp::Any syntax_tree_builder::visitDecl(C1Parser::DeclContext *ctx)
{
    // it can be constdecl or vardecl, but both share the same syntax structure
    // returns a vector
    
    if(ctx.constdecl())
        return static_cast<ptr_list<global_def_syntax>> visit(ctx.constdecl()[0]).as<ptr_list<global_def_syntax>>();
    else if(ctx.vardecl())
        return static_cast<ptr_list<global_def_syntax>> visit(ctx.vardecl()[0]).as<ptr_list<global_def_syntax>>();
}

antlrcpp::Any syntax_tree_builder::visitConstdecl(C1Parser::ConstdeclContext *ctx)
{
    // one decl may contain multiple defs

    decl->line = ctx->getStart()->getLine();
    decl->pos = ctx->getStart()->getCharPositionInLine();

    ptr_list<var_def_stmt_syntax> var_defs;
    auto defs = ctx.constdecl()[0].constdef();
    for(auto def : defs)
    {
        ptr<var_def_stmt_syntax> smart_p;
        smart_p.reset(visit(def).as<var_def_stmt_syntax*>()); // call visitConstdef
        var_defs.push_back(smart_p);
    }
    return var_defs;
}

antlrcpp::Any syntax_tree_builder::visitConstdef(C1Parser::ConstdefContext *ctx)
{
    auto result = new var_def_stmt_syntax;
    auto children = ctx.children;
    result->is_constant = true;
    result->name = def.Identifier().getText();
    // seems the same with def.Identifier().getSymbol().getText()
    if(def.LeftBracket() && def.RightBracket())
    // it's an array
    {
        auto begin = children.begin();
        while(begin!=children.end())
        {
            if(*begin->getSymbol().getType()==C1Parser::LeftBracket)
                break;//we've locate the LeftBracket
            begin++;
        }
        if(antlrcpp::is<C1Parser::ExpContext>(*(++begin)))
            result->array_length = visit(begin).as<expr_syntax*>();
        else
        {
            // deduce the length from number of `exp`
            auto exps = def.exp();
            literal_syntax* num = new literal_syntax;
            num->number = exps.size(); 
            result->array_length = num;
        }
    }
    else
        result->array_length = nullptr;
    return static_cast<var_def_stmt_syntax*> result;
}

antlrcpp::Any syntax_tree_builder::visitVardecl(C1Parser::VardeclContext *ctx)
{
}

antlrcpp::Any syntax_tree_builder::visitVardef(C1Parser::VardefContext *ctx)
{
}

antlrcpp::Any syntax_tree_builder::visitFuncdef(C1Parser::FuncdefContext *ctx)
{
}

antlrcpp::Any syntax_tree_builder::visitBlock(C1Parser::BlockContext *ctx)
{
}

antlrcpp::Any syntax_tree_builder::visitStmt(C1Parser::StmtContext *ctx)
{
}

antlrcpp::Any syntax_tree_builder::visitLval(C1Parser::LvalContext *ctx)
{
}

antlrcpp::Any syntax_tree_builder::visitCond(C1Parser::CondContext *ctx)
{
}

// Returns antlrcpp::Any, which is constructable from any type.
// However, you should be sure you use the same type for packing and depacking the `Any` object.
// Or a std::bad_cast exception will rise.
// This function always returns an `Any` object containing a `expr_syntax *`.
antlrcpp::Any syntax_tree_builder::visitExp(C1Parser::ExpContext *ctx)
{
    // Get all sub-contexts of type `exp`.
    auto expressions = ctx->exp();
    // Two sub-expressions presented: this indicates it's a expression of binary operator, aka `binop`.
    if (expressions.size() == 2)
    {
        auto result = new binop_expr_syntax;
        // Set line and pos.
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        // visit(some context) is equivalent to calling corresponding visit method; dispatching is done automatically
        // by ANTLR4 runtime. For this case, it's equivalent to visitExp(expressions[0]).
        // Use reset to set a new pointer to a std::shared_ptr object. DO NOT use assignment; it won't work.
        // Use `.as<Type>()' to get value from antlrcpp::Any object; notice that this Type must match the type used in
        // constructing the Any object, which is constructed from (usually pointer to some derived class of
        // syntax_node, in this case) returning value of the visit call.
        result->lhs.reset(visit(expressions[0]).as<expr_syntax *>());
        // Check if each token exists.
        // Returnd value of the calling will be nullptr (aka NULL in C) if it isn't there; otherwise non-null pointer.
        if (ctx->Plus())
            result->op = binop::plus;
        if (ctx->Minus())
            result->op = binop::minus;
        if (ctx->Multiply())
            result->op = binop::multiply;
        if (ctx->Divide())
            result->op = binop::divide;
        if (ctx->Modulo())
            result->op = binop::modulo;
        result->rhs.reset(visit(expressions[1]).as<expr_syntax *>());
        return static_cast<expr_syntax *>(result);
    }
    // Otherwise, if `+` or `-` presented, it'll be a `unaryop_expr_syntax`.
    if (ctx->Plus() || ctx->Minus())
    {
        auto result = new unaryop_expr_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        if (ctx->Plus())
            result->op = unaryop::plus;
        if (ctx->Minus())
            result->op = unaryop::minus;
        result->rhs.reset(visit(expressions[0]).as<expr_syntax *>());
        return static_cast<expr_syntax *>(result);
    }
    // In the case that `(` exists as a child, this is an expression like `'(' expressions[0] ')'`.
    if (ctx->LeftParen())
        return visit(expressions[0]); // Any already holds expr_syntax* here, no need for dispatch and re-patch with casting.
    // If `Number` exists as a child, we can say it's a literal integer expression.
    if (auto number = ctx->Number())
    {
        auto result = new literal_syntax;
        result->line = number->getSymbol()->getLine();
        result->pos = number->getSymbol()->getCharPositionInLine();
        auto text = number->getSymbol()->getText();
        if (text[0] == '0' && text[1] == 'x')              // Hexadecimal
            result->number = std::stoi(text, nullptr, 16); // std::stoi will eat '0x'
        else                                               // Decimal
            result->number = std::stoi(text, nullptr, 10);
        return static_cast<expr_syntax *>(result);
    }
}

ptr<syntax_tree_node> syntax_tree_builder::operator()(antlr4::tree::ParseTree *ctx)
{
    auto result = visit(ctx);
    if (result.is<syntax_tree_node *>())
        return ptr<syntax_tree_node>(result.as<syntax_tree_node *>());
    if (result.is<assembly *>())
        return ptr<syntax_tree_node>(result.as<assembly *>());
    if (result.is<global_def_syntax *>())
        return ptr<syntax_tree_node>(result.as<global_def_syntax *>());
    if (result.is<func_def_syntax *>())
        return ptr<syntax_tree_node>(result.as<func_def_syntax *>());
    if (result.is<cond_syntax *>())
        return ptr<syntax_tree_node>(result.as<cond_syntax *>());
    if (result.is<expr_syntax *>())
        return ptr<syntax_tree_node>(result.as<expr_syntax *>());
    if (result.is<binop_expr_syntax *>())
        return ptr<syntax_tree_node>(result.as<binop_expr_syntax *>());
    if (result.is<unaryop_expr_syntax *>())
        return ptr<syntax_tree_node>(result.as<unaryop_expr_syntax *>());
    if (result.is<lval_syntax *>())
        return ptr<syntax_tree_node>(result.as<lval_syntax *>());
    if (result.is<literal_syntax *>())
        return ptr<syntax_tree_node>(result.as<literal_syntax *>());
    if (result.is<stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<stmt_syntax *>());
    if (result.is<var_def_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<var_def_stmt_syntax *>());
    if (result.is<assign_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<assign_stmt_syntax *>());
    if (result.is<func_call_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<func_call_stmt_syntax *>());
    if (result.is<block_syntax *>())
        return ptr<syntax_tree_node>(result.as<block_syntax *>());
    if (result.is<if_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<if_stmt_syntax *>());
    if (result.is<while_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<while_stmt_syntax *>());
    return nullptr;
}

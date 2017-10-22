
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
        {
            ptr<func_def_syntax> p;
            p.reset(visit(item).as<func_def_syntax*>());
            global_defs.push_back(p);
        }
        else if(antlrcpp::is<C1Parser::DeclContext*>(item))
        // it will return a vector containing several var_def_syntaxes
        // we add them to global_defs
        {
            auto var_defs = visit(item).as<ptr_list<global_def_syntax>>();
            for(auto &var_def : var_defs)
                global_defs.push_back(var_def);
        }
    }
    return static_cast<ptr_list<global_def_syntax>> (global_defs);
}

antlrcpp::Any syntax_tree_builder::visitDecl(C1Parser::DeclContext *ctx)
{
    // it can be constdecl or vardecl, but both share the same syntax structure
    // returns a vector
    
    if(ctx->constdecl())
        return static_cast<ptr_list<global_def_syntax>> (visit(ctx->constdecl()).as<ptr_list<global_def_syntax>>());
    else if(ctx->vardecl())
        return static_cast<ptr_list<var_def_stmt_syntax>> (visit(ctx->vardecl()).as<ptr_list<var_def_stmt_syntax>>());
}

antlrcpp::Any syntax_tree_builder::visitConstdecl(C1Parser::ConstdeclContext *ctx)
{
    // one decl may contain multiple defs

    ptr_list<var_def_stmt_syntax> var_defs;
    auto defs = ctx->constdef();
    for(auto &def : defs)
    {
        ptr<var_def_stmt_syntax> smart_p;
        smart_p.reset(visit(def).as<var_def_stmt_syntax*>()); // call visitConstdef
        var_defs.push_back(smart_p);
    }
    return var_defs;
}

antlrcpp::Any syntax_tree_builder::visitConstdef(C1Parser::ConstdefContext *ctx)
{
    // there is always an initializer in constdef
    auto result = new var_def_stmt_syntax;
    auto children = ctx->children;
    auto exps = ctx->exp();
    auto first_exp_it = exps.begin();
    
    result->is_constant = true;
    result->name = ctx->Identifier()->getText();
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    // seems the same with def.Identifier().getSymbol().getText()
    if(ctx->LeftBracket() && ctx->RightBracket())
    // it's an array
    {
        auto it = children.begin();
        // determines if there is an `exp` immediately after `LeftBracket`
        while(it!=children.end())
        {
            if(antlrcpp::is<antlr4::tree::TerminalNode *>(*it))
            {
                antlr4::tree::TerminalNode *tnode = dynamic_cast<antlr4::tree::TerminalNode *>(*it);
                if(tnode->getSymbol()->getType()==C1Parser::LeftBracket)
                    break;//we've locate the LeftBracket
            }
            it++;
        }
        if(antlrcpp::is<C1Parser::ExpContext*>(*(++it)))
        {
            result->array_length.reset( visit(*it).as<expr_syntax*>());
            first_exp_it++; //skip the first exp, since it's the length
        }
        else
        {
            // deduce the length from number of `exp`
            literal_syntax* num = new literal_syntax;
            num->number = exps.size(); 
            result->array_length.reset( num );
        }
        
    }
    else
    // it's a variable
        result->array_length = nullptr;
    for(;first_exp_it<exps.end();first_exp_it++)
    {
        ptr<expr_syntax> initializer;
        initializer.reset(visit(*first_exp_it).as<expr_syntax*>());
        result->initializers.push_back(initializer);
    }
    return static_cast<var_def_stmt_syntax*> (result);
}

antlrcpp::Any syntax_tree_builder::visitVardecl(C1Parser::VardeclContext *ctx)
{
    // one decl may contain multiple defs
    ptr_list<var_def_stmt_syntax> var_defs;
    auto defs = ctx->vardef();
    for(auto &def : defs)
    {
        ptr<var_def_stmt_syntax> smart_p;
        smart_p.reset(visit(def).as<var_def_stmt_syntax*>());
        var_defs.push_back(smart_p);
    }
    return var_defs;

}

antlrcpp::Any syntax_tree_builder::visitVardef(C1Parser::VardefContext *ctx)
{
    auto result = new var_def_stmt_syntax;
    auto children = ctx->children;
    auto exps = ctx->exp();
    auto first_exp_it = exps.begin();
    result->is_constant = false;
    result->name = ctx->Identifier()->getText();
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    // different to constdef, there can be no `assign`
    if(ctx->Assign())
    {
        if(ctx->LeftBracket() && ctx->RightBracket())
        {
            // the same case with constdef
            auto it = children.begin();
            // determines if there is an `exp` immediately after `LeftBracket`
            while(it!=children.end())
            {
                if(antlrcpp::is<antlr4::tree::TerminalNode *>(*it))
                {
                    antlr4::tree::TerminalNode *tnode = dynamic_cast<antlr4::tree::TerminalNode *>(*it);
                    if(tnode->getSymbol()->getType()==C1Parser::LeftBracket)
                        break;//we've locate the LeftBracket
                }
                it++;
            }
            if(antlrcpp::is<C1Parser::ExpContext*>(*(++it)))
            {
                result->array_length.reset( visit(*it).as<expr_syntax*>());
                first_exp_it++; //skip the first exp, since it's the length
            }
            else
            {
                // deduce the length from number of `exp`
                literal_syntax* num = new literal_syntax;
                num->number = exps.size(); 
                result->array_length.reset( num );
            }
        }
        else
            result->array_length = nullptr;
        // fill exps into initializeirs
        for(;first_exp_it<exps.end();first_exp_it++)
        {
            ptr<expr_syntax> initializer;
            initializer.reset(visit(*first_exp_it).as<expr_syntax*>());
            result->initializers.push_back(initializer);
        }
    }
    else
        if(ctx->exp().size()>=1) // it must be the array length
            result->array_length.reset(visit(ctx->exp()[0]).as<expr_syntax*>());
        else
            result->array_length = nullptr;

    return result;
}

antlrcpp::Any syntax_tree_builder::visitFuncdef(C1Parser::FuncdefContext *ctx)
{
    auto result = new func_def_syntax;
    
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->name = ctx->Identifier()->getText();
    result->body.reset(visit(ctx->block()).as<block_syntax*>()); //
    return result;
}

antlrcpp::Any syntax_tree_builder::visitBlock(C1Parser::BlockContext *ctx)
{
    auto block = new block_syntax;
    block->line = ctx->getStart()->getLine();
    block->pos = ctx->getStart()->getCharPositionInLine();
    auto items = ctx->blockitem();
    for(auto &item : items)
    {
        // first, judge whether the item is a stmt or a decl.
        if(item->decl())
        // one decl may produce several stmts(defs)
        {
            
            auto stmts = visit(item->decl()).as<ptr_list<var_def_stmt_syntax>>();
            for(auto &stmt : stmts)
                block->body.push_back(stmt);
        }
        else if(item->stmt())
        // only one stmt
        {
            ptr<stmt_syntax> p_item;
            p_item.reset(visit(item->stmt()).as<stmt_syntax*>());
            // the unoverrided function visitBlockitem will call visitDecl and visitStmt
            block->body.push_back(p_item);
        }
    }
    return block;
}

antlrcpp::Any syntax_tree_builder::visitStmt(C1Parser::StmtContext *ctx)
{
    // 6 alternatives
    if(ctx->lval()) // 1st
    {
        auto stmt = new assign_stmt_syntax;
        stmt->line = ctx->getStart()->getLine();
        stmt->pos = ctx->getStart()->getCharPositionInLine();
        stmt->target.reset(visit(ctx->lval()).as<lval_syntax*>());
        stmt->value.reset(visit(ctx->exp()).as<expr_syntax*>());
        return stmt;
    }
    if(ctx->Identifier()) //2nd
    {
        auto stmt = new func_call_stmt_syntax;
        stmt->line = ctx->getStart()->getLine();
        stmt->pos = ctx->getStart()->getCharPositionInLine();
        stmt->name = ctx->Identifier()->getText();
        return stmt;
    }
    if(ctx->block()) //3rd
        return visit(ctx->block()).as<block_syntax*>();
    if(ctx->If()) //4th
    {
        auto stmt = new if_stmt_syntax;
        stmt->line = ctx->getStart()->getLine();
        stmt->pos = ctx->getStart()->getCharPositionInLine();
        stmt->pred.reset(visit(ctx->cond()).as<cond_syntax*>());
        stmt->then_body.reset(visit(ctx->stmt(0)).as<stmt_syntax*>());
        if(ctx->Else())
            stmt->else_body.reset(visit(ctx->stmt(1)).as<stmt_syntax*>());
        else stmt->else_body = nullptr;
        return stmt;
    }
    if(ctx->While()) //5th
    {
        auto stmt = new while_stmt_syntax;
        stmt->line = ctx->getStart()->getLine();
        stmt->pos = ctx->getStart()->getCharPositionInLine();
        stmt->pred.reset(visit(ctx->cond()).as<cond_syntax*>());
        stmt->body.reset(visit(ctx->stmt(0)).as<stmt_syntax*>());
        return stmt;
    }
    if(antlrcpp::is<antlr4::tree::TerminalNode *>(ctx->children[0])) // 6th
    {
        antlr4::tree::TerminalNode *tnode = dynamic_cast<antlr4::tree::TerminalNode *>(ctx->children[0]);
        if(tnode->getSymbol()->getType()==C1Parser::SemiColon)
        {
            auto empty_stmt = new empty_stmt_syntax;
            empty_stmt->line = ctx->getStart()->getLine();
            empty_stmt->pos = ctx->getStart()->getCharPositionInLine();
            return empty_stmt; 
        }
    }
    return new var_def_stmt_syntax; // never here
}

antlrcpp::Any syntax_tree_builder::visitLval(C1Parser::LvalContext *ctx)
{
    auto lval = new lval_syntax;
    lval->line = ctx->getStart()->getLine();
    lval->pos = ctx->getStart()->getCharPositionInLine();
    lval->name = ctx->Identifier()->getText();
    if(ctx->exp())
        lval->array_index.reset(visit(ctx->exp()).as<expr_syntax*>());
    return lval;
}

antlrcpp::Any syntax_tree_builder::visitCond(C1Parser::CondContext *ctx)
{
    auto cond = new cond_syntax;
    cond->line = ctx->getStart()->getLine();
    cond->pos = ctx->getStart()->getCharPositionInLine();
    cond->lhs.reset(visit(ctx->exp(0)).as<expr_syntax*>());
    cond->rhs.reset(visit(ctx->exp(1)).as<expr_syntax*>());
    if(ctx->relop()->Equal())
        cond->op = relop::equal;
    if(ctx->relop()->NonEqual())
        cond->op = relop::non_equal;
    if(ctx->relop()->Less())
        cond->op = relop::less;
    if(ctx->relop()->Greater())
        cond->op = relop::greater;
    if(ctx->relop()->LessEqual())
        cond->op = relop::less_equal;
    if(ctx->relop()->GreaterEqual())
        cond->op = relop::greater_equal;
    return cond;
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

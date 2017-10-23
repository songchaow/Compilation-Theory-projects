
// Generated from C1Parser.g4 by ANTLR 4.7


#include "C1ParserListener.h"
#include "C1ParserVisitor.h"

#include "C1Parser.h"


using namespace antlrcpp;
using namespace antlr4;

C1Parser::C1Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

C1Parser::~C1Parser() {
  delete _interpreter;
}

std::string C1Parser::getGrammarFileName() const {
  return "C1Parser.g4";
}

const std::vector<std::string>& C1Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& C1Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompilationUnitContext ------------------------------------------------------------------

C1Parser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C1Parser::CompilationUnitContext::EOF() {
  return getToken(C1Parser::EOF, 0);
}

std::vector<C1Parser::FuncdefContext *> C1Parser::CompilationUnitContext::funcdef() {
  return getRuleContexts<C1Parser::FuncdefContext>();
}

C1Parser::FuncdefContext* C1Parser::CompilationUnitContext::funcdef(size_t i) {
  return getRuleContext<C1Parser::FuncdefContext>(i);
}

std::vector<C1Parser::DeclContext *> C1Parser::CompilationUnitContext::decl() {
  return getRuleContexts<C1Parser::DeclContext>();
}

C1Parser::DeclContext* C1Parser::CompilationUnitContext::decl(size_t i) {
  return getRuleContext<C1Parser::DeclContext>(i);
}


size_t C1Parser::CompilationUnitContext::getRuleIndex() const {
  return C1Parser::RuleCompilationUnit;
}

void C1Parser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void C1Parser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}


antlrcpp::Any C1Parser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::CompilationUnitContext* C1Parser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, C1Parser::RuleCompilationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(34);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case C1Parser::Void: {
          setState(32);
          funcdef();
          break;
        }

        case C1Parser::Const:
        case C1Parser::Int:
        case C1Parser::Identifier: {
          setState(33);
          decl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(36); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << C1Parser::Const)
      | (1ULL << C1Parser::Int)
      | (1ULL << C1Parser::Void)
      | (1ULL << C1Parser::Identifier))) != 0));
    setState(38);
    match(C1Parser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

C1Parser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C1Parser::ConstdeclContext* C1Parser::DeclContext::constdecl() {
  return getRuleContext<C1Parser::ConstdeclContext>(0);
}

C1Parser::VardeclContext* C1Parser::DeclContext::vardecl() {
  return getRuleContext<C1Parser::VardeclContext>(0);
}


size_t C1Parser::DeclContext::getRuleIndex() const {
  return C1Parser::RuleDecl;
}

void C1Parser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void C1Parser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}


antlrcpp::Any C1Parser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::DeclContext* C1Parser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, C1Parser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(42);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C1Parser::Const: {
        enterOuterAlt(_localctx, 1);
        setState(40);
        constdecl();
        break;
      }

      case C1Parser::Int:
      case C1Parser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(41);
        vardecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstdeclContext ------------------------------------------------------------------

C1Parser::ConstdeclContext::ConstdeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C1Parser::ConstdeclContext::Const() {
  return getToken(C1Parser::Const, 0);
}

tree::TerminalNode* C1Parser::ConstdeclContext::Int() {
  return getToken(C1Parser::Int, 0);
}

std::vector<C1Parser::ConstdefContext *> C1Parser::ConstdeclContext::constdef() {
  return getRuleContexts<C1Parser::ConstdefContext>();
}

C1Parser::ConstdefContext* C1Parser::ConstdeclContext::constdef(size_t i) {
  return getRuleContext<C1Parser::ConstdefContext>(i);
}

tree::TerminalNode* C1Parser::ConstdeclContext::SemiColon() {
  return getToken(C1Parser::SemiColon, 0);
}

std::vector<tree::TerminalNode *> C1Parser::ConstdeclContext::Comma() {
  return getTokens(C1Parser::Comma);
}

tree::TerminalNode* C1Parser::ConstdeclContext::Comma(size_t i) {
  return getToken(C1Parser::Comma, i);
}


size_t C1Parser::ConstdeclContext::getRuleIndex() const {
  return C1Parser::RuleConstdecl;
}

void C1Parser::ConstdeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstdecl(this);
}

void C1Parser::ConstdeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstdecl(this);
}


antlrcpp::Any C1Parser::ConstdeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitConstdecl(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::ConstdeclContext* C1Parser::constdecl() {
  ConstdeclContext *_localctx = _tracker.createInstance<ConstdeclContext>(_ctx, getState());
  enterRule(_localctx, 4, C1Parser::RuleConstdecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(67);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(44);
      match(C1Parser::Const);
      setState(45);
      match(C1Parser::Int);
      setState(46);
      constdef();
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == C1Parser::Comma) {
        setState(47);
        match(C1Parser::Comma);
        setState(48);
        constdef();
        setState(53);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(54);
      match(C1Parser::SemiColon);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(56);
      match(C1Parser::Const);
      setState(57);
      constdef();
      setState(62);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == C1Parser::Comma) {
        setState(58);
        match(C1Parser::Comma);
        setState(59);
        constdef();
        setState(64);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(65);
      match(C1Parser::SemiColon);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstdefContext ------------------------------------------------------------------

C1Parser::ConstdefContext::ConstdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C1Parser::ConstdefContext::Identifier() {
  return getToken(C1Parser::Identifier, 0);
}

tree::TerminalNode* C1Parser::ConstdefContext::Assign() {
  return getToken(C1Parser::Assign, 0);
}

std::vector<C1Parser::ExpContext *> C1Parser::ConstdefContext::exp() {
  return getRuleContexts<C1Parser::ExpContext>();
}

C1Parser::ExpContext* C1Parser::ConstdefContext::exp(size_t i) {
  return getRuleContext<C1Parser::ExpContext>(i);
}

tree::TerminalNode* C1Parser::ConstdefContext::LeftBracket() {
  return getToken(C1Parser::LeftBracket, 0);
}

tree::TerminalNode* C1Parser::ConstdefContext::RightBracket() {
  return getToken(C1Parser::RightBracket, 0);
}

tree::TerminalNode* C1Parser::ConstdefContext::LeftBrace() {
  return getToken(C1Parser::LeftBrace, 0);
}

tree::TerminalNode* C1Parser::ConstdefContext::RightBrace() {
  return getToken(C1Parser::RightBrace, 0);
}

std::vector<tree::TerminalNode *> C1Parser::ConstdefContext::Comma() {
  return getTokens(C1Parser::Comma);
}

tree::TerminalNode* C1Parser::ConstdefContext::Comma(size_t i) {
  return getToken(C1Parser::Comma, i);
}


size_t C1Parser::ConstdefContext::getRuleIndex() const {
  return C1Parser::RuleConstdef;
}

void C1Parser::ConstdefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstdef(this);
}

void C1Parser::ConstdefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstdef(this);
}


antlrcpp::Any C1Parser::ConstdefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitConstdef(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::ConstdefContext* C1Parser::constdef() {
  ConstdefContext *_localctx = _tracker.createInstance<ConstdefContext>(_ctx, getState());
  enterRule(_localctx, 6, C1Parser::RuleConstdef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(90);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(69);
      match(C1Parser::Identifier);
      setState(70);
      match(C1Parser::Assign);
      setState(71);
      exp(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(72);
      match(C1Parser::Identifier);
      setState(73);
      match(C1Parser::LeftBracket);
      setState(75);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << C1Parser::LeftParen)
        | (1ULL << C1Parser::Plus)
        | (1ULL << C1Parser::Minus)
        | (1ULL << C1Parser::Identifier)
        | (1ULL << C1Parser::Number))) != 0)) {
        setState(74);
        exp(0);
      }
      setState(77);
      match(C1Parser::RightBracket);
      setState(78);
      match(C1Parser::Assign);
      setState(79);
      match(C1Parser::LeftBrace);
      setState(80);
      exp(0);
      setState(85);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == C1Parser::Comma) {
        setState(81);
        match(C1Parser::Comma);
        setState(82);
        exp(0);
        setState(87);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(88);
      match(C1Parser::RightBrace);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VardeclContext ------------------------------------------------------------------

C1Parser::VardeclContext::VardeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C1Parser::VardeclContext::Int() {
  return getToken(C1Parser::Int, 0);
}

std::vector<C1Parser::VardefContext *> C1Parser::VardeclContext::vardef() {
  return getRuleContexts<C1Parser::VardefContext>();
}

C1Parser::VardefContext* C1Parser::VardeclContext::vardef(size_t i) {
  return getRuleContext<C1Parser::VardefContext>(i);
}

tree::TerminalNode* C1Parser::VardeclContext::SemiColon() {
  return getToken(C1Parser::SemiColon, 0);
}

std::vector<tree::TerminalNode *> C1Parser::VardeclContext::Comma() {
  return getTokens(C1Parser::Comma);
}

tree::TerminalNode* C1Parser::VardeclContext::Comma(size_t i) {
  return getToken(C1Parser::Comma, i);
}


size_t C1Parser::VardeclContext::getRuleIndex() const {
  return C1Parser::RuleVardecl;
}

void C1Parser::VardeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardecl(this);
}

void C1Parser::VardeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardecl(this);
}


antlrcpp::Any C1Parser::VardeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitVardecl(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::VardeclContext* C1Parser::vardecl() {
  VardeclContext *_localctx = _tracker.createInstance<VardeclContext>(_ctx, getState());
  enterRule(_localctx, 8, C1Parser::RuleVardecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(113);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C1Parser::Int: {
        enterOuterAlt(_localctx, 1);
        setState(92);
        match(C1Parser::Int);
        setState(93);
        vardef();
        setState(98);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == C1Parser::Comma) {
          setState(94);
          match(C1Parser::Comma);
          setState(95);
          vardef();
          setState(100);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(101);
        match(C1Parser::SemiColon);
        break;
      }

      case C1Parser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(103);
        vardef();
        setState(108);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == C1Parser::Comma) {
          setState(104);
          match(C1Parser::Comma);
          setState(105);
          vardef();
          setState(110);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(111);
        match(C1Parser::SemiColon);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VardefContext ------------------------------------------------------------------

C1Parser::VardefContext::VardefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C1Parser::VardefContext::Identifier() {
  return getToken(C1Parser::Identifier, 0);
}

tree::TerminalNode* C1Parser::VardefContext::LeftBracket() {
  return getToken(C1Parser::LeftBracket, 0);
}

std::vector<C1Parser::ExpContext *> C1Parser::VardefContext::exp() {
  return getRuleContexts<C1Parser::ExpContext>();
}

C1Parser::ExpContext* C1Parser::VardefContext::exp(size_t i) {
  return getRuleContext<C1Parser::ExpContext>(i);
}

tree::TerminalNode* C1Parser::VardefContext::RightBracket() {
  return getToken(C1Parser::RightBracket, 0);
}

tree::TerminalNode* C1Parser::VardefContext::Assign() {
  return getToken(C1Parser::Assign, 0);
}

tree::TerminalNode* C1Parser::VardefContext::LeftBrace() {
  return getToken(C1Parser::LeftBrace, 0);
}

tree::TerminalNode* C1Parser::VardefContext::RightBrace() {
  return getToken(C1Parser::RightBrace, 0);
}

std::vector<tree::TerminalNode *> C1Parser::VardefContext::Comma() {
  return getTokens(C1Parser::Comma);
}

tree::TerminalNode* C1Parser::VardefContext::Comma(size_t i) {
  return getToken(C1Parser::Comma, i);
}


size_t C1Parser::VardefContext::getRuleIndex() const {
  return C1Parser::RuleVardef;
}

void C1Parser::VardefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardef(this);
}

void C1Parser::VardefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardef(this);
}


antlrcpp::Any C1Parser::VardefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitVardef(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::VardefContext* C1Parser::vardef() {
  VardefContext *_localctx = _tracker.createInstance<VardefContext>(_ctx, getState());
  enterRule(_localctx, 10, C1Parser::RuleVardef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(142);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(115);
      match(C1Parser::Identifier);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(116);
      match(C1Parser::Identifier);
      setState(117);
      match(C1Parser::LeftBracket);
      setState(118);
      exp(0);
      setState(119);
      match(C1Parser::RightBracket);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(121);
      match(C1Parser::Identifier);
      setState(122);
      match(C1Parser::Assign);
      setState(123);
      exp(0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(124);
      match(C1Parser::Identifier);
      setState(125);
      match(C1Parser::LeftBracket);
      setState(127);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << C1Parser::LeftParen)
        | (1ULL << C1Parser::Plus)
        | (1ULL << C1Parser::Minus)
        | (1ULL << C1Parser::Identifier)
        | (1ULL << C1Parser::Number))) != 0)) {
        setState(126);
        exp(0);
      }
      setState(129);
      match(C1Parser::RightBracket);
      setState(130);
      match(C1Parser::Assign);
      setState(131);
      match(C1Parser::LeftBrace);
      setState(132);
      exp(0);
      setState(137);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == C1Parser::Comma) {
        setState(133);
        match(C1Parser::Comma);
        setState(134);
        exp(0);
        setState(139);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(140);
      match(C1Parser::RightBrace);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncdefContext ------------------------------------------------------------------

C1Parser::FuncdefContext::FuncdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C1Parser::FuncdefContext::Void() {
  return getToken(C1Parser::Void, 0);
}

tree::TerminalNode* C1Parser::FuncdefContext::Identifier() {
  return getToken(C1Parser::Identifier, 0);
}

tree::TerminalNode* C1Parser::FuncdefContext::LeftParen() {
  return getToken(C1Parser::LeftParen, 0);
}

tree::TerminalNode* C1Parser::FuncdefContext::RightParen() {
  return getToken(C1Parser::RightParen, 0);
}

C1Parser::BlockContext* C1Parser::FuncdefContext::block() {
  return getRuleContext<C1Parser::BlockContext>(0);
}


size_t C1Parser::FuncdefContext::getRuleIndex() const {
  return C1Parser::RuleFuncdef;
}

void C1Parser::FuncdefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncdef(this);
}

void C1Parser::FuncdefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncdef(this);
}


antlrcpp::Any C1Parser::FuncdefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitFuncdef(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::FuncdefContext* C1Parser::funcdef() {
  FuncdefContext *_localctx = _tracker.createInstance<FuncdefContext>(_ctx, getState());
  enterRule(_localctx, 12, C1Parser::RuleFuncdef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(C1Parser::Void);
    setState(145);
    match(C1Parser::Identifier);
    setState(146);
    match(C1Parser::LeftParen);
    setState(147);
    match(C1Parser::RightParen);
    setState(148);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

C1Parser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C1Parser::BlockContext::LeftBrace() {
  return getToken(C1Parser::LeftBrace, 0);
}

tree::TerminalNode* C1Parser::BlockContext::RightBrace() {
  return getToken(C1Parser::RightBrace, 0);
}

std::vector<C1Parser::BlockitemContext *> C1Parser::BlockContext::blockitem() {
  return getRuleContexts<C1Parser::BlockitemContext>();
}

C1Parser::BlockitemContext* C1Parser::BlockContext::blockitem(size_t i) {
  return getRuleContext<C1Parser::BlockitemContext>(i);
}


size_t C1Parser::BlockContext::getRuleIndex() const {
  return C1Parser::RuleBlock;
}

void C1Parser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void C1Parser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any C1Parser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::BlockContext* C1Parser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 14, C1Parser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    match(C1Parser::LeftBrace);
    setState(154);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << C1Parser::SemiColon)
      | (1ULL << C1Parser::LeftBrace)
      | (1ULL << C1Parser::If)
      | (1ULL << C1Parser::While)
      | (1ULL << C1Parser::Const)
      | (1ULL << C1Parser::Int)
      | (1ULL << C1Parser::Identifier))) != 0)) {
      setState(151);
      blockitem();
      setState(156);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(157);
    match(C1Parser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockitemContext ------------------------------------------------------------------

C1Parser::BlockitemContext::BlockitemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C1Parser::StmtContext* C1Parser::BlockitemContext::stmt() {
  return getRuleContext<C1Parser::StmtContext>(0);
}

C1Parser::DeclContext* C1Parser::BlockitemContext::decl() {
  return getRuleContext<C1Parser::DeclContext>(0);
}


size_t C1Parser::BlockitemContext::getRuleIndex() const {
  return C1Parser::RuleBlockitem;
}

void C1Parser::BlockitemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockitem(this);
}

void C1Parser::BlockitemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockitem(this);
}


antlrcpp::Any C1Parser::BlockitemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitBlockitem(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::BlockitemContext* C1Parser::blockitem() {
  BlockitemContext *_localctx = _tracker.createInstance<BlockitemContext>(_ctx, getState());
  enterRule(_localctx, 16, C1Parser::RuleBlockitem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(161);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(159);
      stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(160);
      decl();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

C1Parser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C1Parser::LvalContext* C1Parser::StmtContext::lval() {
  return getRuleContext<C1Parser::LvalContext>(0);
}

tree::TerminalNode* C1Parser::StmtContext::Assign() {
  return getToken(C1Parser::Assign, 0);
}

C1Parser::ExpContext* C1Parser::StmtContext::exp() {
  return getRuleContext<C1Parser::ExpContext>(0);
}

tree::TerminalNode* C1Parser::StmtContext::SemiColon() {
  return getToken(C1Parser::SemiColon, 0);
}

tree::TerminalNode* C1Parser::StmtContext::Identifier() {
  return getToken(C1Parser::Identifier, 0);
}

tree::TerminalNode* C1Parser::StmtContext::LeftParen() {
  return getToken(C1Parser::LeftParen, 0);
}

tree::TerminalNode* C1Parser::StmtContext::RightParen() {
  return getToken(C1Parser::RightParen, 0);
}

C1Parser::BlockContext* C1Parser::StmtContext::block() {
  return getRuleContext<C1Parser::BlockContext>(0);
}

tree::TerminalNode* C1Parser::StmtContext::If() {
  return getToken(C1Parser::If, 0);
}

C1Parser::CondContext* C1Parser::StmtContext::cond() {
  return getRuleContext<C1Parser::CondContext>(0);
}

std::vector<C1Parser::StmtContext *> C1Parser::StmtContext::stmt() {
  return getRuleContexts<C1Parser::StmtContext>();
}

C1Parser::StmtContext* C1Parser::StmtContext::stmt(size_t i) {
  return getRuleContext<C1Parser::StmtContext>(i);
}

tree::TerminalNode* C1Parser::StmtContext::Else() {
  return getToken(C1Parser::Else, 0);
}

tree::TerminalNode* C1Parser::StmtContext::While() {
  return getToken(C1Parser::While, 0);
}


size_t C1Parser::StmtContext::getRuleIndex() const {
  return C1Parser::RuleStmt;
}

void C1Parser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void C1Parser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


antlrcpp::Any C1Parser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::StmtContext* C1Parser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 18, C1Parser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(163);
      lval();
      setState(164);
      match(C1Parser::Assign);
      setState(165);
      exp(0);
      setState(166);
      match(C1Parser::SemiColon);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(168);
      match(C1Parser::Identifier);
      setState(169);
      match(C1Parser::LeftParen);
      setState(170);
      match(C1Parser::RightParen);
      setState(171);
      match(C1Parser::SemiColon);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(172);
      block();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(173);
      match(C1Parser::If);
      setState(174);
      match(C1Parser::LeftParen);
      setState(175);
      cond();
      setState(176);
      match(C1Parser::RightParen);
      setState(177);
      stmt();
      setState(180);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
      case 1: {
        setState(178);
        match(C1Parser::Else);
        setState(179);
        stmt();
        break;
      }

      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(182);
      match(C1Parser::While);
      setState(183);
      match(C1Parser::LeftParen);
      setState(184);
      cond();
      setState(185);
      match(C1Parser::RightParen);
      setState(186);
      stmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(188);
      match(C1Parser::SemiColon);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LvalContext ------------------------------------------------------------------

C1Parser::LvalContext::LvalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C1Parser::LvalContext::Identifier() {
  return getToken(C1Parser::Identifier, 0);
}

C1Parser::ExpContext* C1Parser::LvalContext::exp() {
  return getRuleContext<C1Parser::ExpContext>(0);
}


size_t C1Parser::LvalContext::getRuleIndex() const {
  return C1Parser::RuleLval;
}

void C1Parser::LvalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLval(this);
}

void C1Parser::LvalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLval(this);
}


antlrcpp::Any C1Parser::LvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitLval(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::LvalContext* C1Parser::lval() {
  LvalContext *_localctx = _tracker.createInstance<LvalContext>(_ctx, getState());
  enterRule(_localctx, 20, C1Parser::RuleLval);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(197);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(191);
      match(C1Parser::Identifier);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(192);
      match(C1Parser::Identifier);
      setState(193);
      match(C1Parser::LeftBracket);
      setState(194);
      exp(0);
      setState(195);
      match(C1Parser::RightBracket);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

C1Parser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C1Parser::ExpContext *> C1Parser::CondContext::exp() {
  return getRuleContexts<C1Parser::ExpContext>();
}

C1Parser::ExpContext* C1Parser::CondContext::exp(size_t i) {
  return getRuleContext<C1Parser::ExpContext>(i);
}

C1Parser::RelopContext* C1Parser::CondContext::relop() {
  return getRuleContext<C1Parser::RelopContext>(0);
}


size_t C1Parser::CondContext::getRuleIndex() const {
  return C1Parser::RuleCond;
}

void C1Parser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void C1Parser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}


antlrcpp::Any C1Parser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::CondContext* C1Parser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 22, C1Parser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    exp(0);
    setState(200);
    relop();
    setState(201);
    exp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelopContext ------------------------------------------------------------------

C1Parser::RelopContext::RelopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C1Parser::RelopContext::Equal() {
  return getToken(C1Parser::Equal, 0);
}

tree::TerminalNode* C1Parser::RelopContext::NonEqual() {
  return getToken(C1Parser::NonEqual, 0);
}

tree::TerminalNode* C1Parser::RelopContext::Less() {
  return getToken(C1Parser::Less, 0);
}

tree::TerminalNode* C1Parser::RelopContext::Greater() {
  return getToken(C1Parser::Greater, 0);
}

tree::TerminalNode* C1Parser::RelopContext::LessEqual() {
  return getToken(C1Parser::LessEqual, 0);
}

tree::TerminalNode* C1Parser::RelopContext::GreaterEqual() {
  return getToken(C1Parser::GreaterEqual, 0);
}


size_t C1Parser::RelopContext::getRuleIndex() const {
  return C1Parser::RuleRelop;
}

void C1Parser::RelopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelop(this);
}

void C1Parser::RelopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelop(this);
}


antlrcpp::Any C1Parser::RelopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitRelop(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::RelopContext* C1Parser::relop() {
  RelopContext *_localctx = _tracker.createInstance<RelopContext>(_ctx, getState());
  enterRule(_localctx, 24, C1Parser::RuleRelop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << C1Parser::Equal)
      | (1ULL << C1Parser::NonEqual)
      | (1ULL << C1Parser::Less)
      | (1ULL << C1Parser::Greater)
      | (1ULL << C1Parser::LessEqual)
      | (1ULL << C1Parser::GreaterEqual))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

C1Parser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C1Parser::ExpContext *> C1Parser::ExpContext::exp() {
  return getRuleContexts<C1Parser::ExpContext>();
}

C1Parser::ExpContext* C1Parser::ExpContext::exp(size_t i) {
  return getRuleContext<C1Parser::ExpContext>(i);
}

tree::TerminalNode* C1Parser::ExpContext::Plus() {
  return getToken(C1Parser::Plus, 0);
}

tree::TerminalNode* C1Parser::ExpContext::Minus() {
  return getToken(C1Parser::Minus, 0);
}

tree::TerminalNode* C1Parser::ExpContext::LeftParen() {
  return getToken(C1Parser::LeftParen, 0);
}

tree::TerminalNode* C1Parser::ExpContext::RightParen() {
  return getToken(C1Parser::RightParen, 0);
}

C1Parser::LvalContext* C1Parser::ExpContext::lval() {
  return getRuleContext<C1Parser::LvalContext>(0);
}

tree::TerminalNode* C1Parser::ExpContext::Number() {
  return getToken(C1Parser::Number, 0);
}

tree::TerminalNode* C1Parser::ExpContext::Multiply() {
  return getToken(C1Parser::Multiply, 0);
}

tree::TerminalNode* C1Parser::ExpContext::Divide() {
  return getToken(C1Parser::Divide, 0);
}

tree::TerminalNode* C1Parser::ExpContext::Modulo() {
  return getToken(C1Parser::Modulo, 0);
}


size_t C1Parser::ExpContext::getRuleIndex() const {
  return C1Parser::RuleExp;
}

void C1Parser::ExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp(this);
}

void C1Parser::ExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp(this);
}


antlrcpp::Any C1Parser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}


C1Parser::ExpContext* C1Parser::exp() {
   return exp(0);
}

C1Parser::ExpContext* C1Parser::exp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C1Parser::ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, parentState);
  C1Parser::ExpContext *previousContext = _localctx;
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, C1Parser::RuleExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(214);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C1Parser::Plus:
      case C1Parser::Minus: {
        setState(206);
        _la = _input->LA(1);
        if (!(_la == C1Parser::Plus

        || _la == C1Parser::Minus)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(207);
        exp(4);
        break;
      }

      case C1Parser::LeftParen: {
        setState(208);
        match(C1Parser::LeftParen);
        setState(209);
        exp(0);
        setState(210);
        match(C1Parser::RightParen);
        break;
      }

      case C1Parser::Identifier: {
        setState(212);
        lval();
        break;
      }

      case C1Parser::Number: {
        setState(213);
        match(C1Parser::Number);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(224);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(222);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(216);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(217);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << C1Parser::Multiply)
            | (1ULL << C1Parser::Divide)
            | (1ULL << C1Parser::Modulo))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(218);
          exp(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(219);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(220);
          _la = _input->LA(1);
          if (!(_la == C1Parser::Plus

          || _la == C1Parser::Minus)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(221);
          exp(6);
          break;
        }

        } 
      }
      setState(226);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BinopContext ------------------------------------------------------------------

C1Parser::BinopContext::BinopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C1Parser::BinopContext::Plus() {
  return getToken(C1Parser::Plus, 0);
}

tree::TerminalNode* C1Parser::BinopContext::Minus() {
  return getToken(C1Parser::Minus, 0);
}

tree::TerminalNode* C1Parser::BinopContext::Multiply() {
  return getToken(C1Parser::Multiply, 0);
}

tree::TerminalNode* C1Parser::BinopContext::Divide() {
  return getToken(C1Parser::Divide, 0);
}

tree::TerminalNode* C1Parser::BinopContext::Modulo() {
  return getToken(C1Parser::Modulo, 0);
}


size_t C1Parser::BinopContext::getRuleIndex() const {
  return C1Parser::RuleBinop;
}

void C1Parser::BinopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinop(this);
}

void C1Parser::BinopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinop(this);
}


antlrcpp::Any C1Parser::BinopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitBinop(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::BinopContext* C1Parser::binop() {
  BinopContext *_localctx = _tracker.createInstance<BinopContext>(_ctx, getState());
  enterRule(_localctx, 28, C1Parser::RuleBinop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << C1Parser::Plus)
      | (1ULL << C1Parser::Minus)
      | (1ULL << C1Parser::Multiply)
      | (1ULL << C1Parser::Divide)
      | (1ULL << C1Parser::Modulo))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryopContext ------------------------------------------------------------------

C1Parser::UnaryopContext::UnaryopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C1Parser::UnaryopContext::Plus() {
  return getToken(C1Parser::Plus, 0);
}

tree::TerminalNode* C1Parser::UnaryopContext::Minus() {
  return getToken(C1Parser::Minus, 0);
}


size_t C1Parser::UnaryopContext::getRuleIndex() const {
  return C1Parser::RuleUnaryop;
}

void C1Parser::UnaryopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryop(this);
}

void C1Parser::UnaryopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryop(this);
}


antlrcpp::Any C1Parser::UnaryopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitUnaryop(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::UnaryopContext* C1Parser::unaryop() {
  UnaryopContext *_localctx = _tracker.createInstance<UnaryopContext>(_ctx, getState());
  enterRule(_localctx, 30, C1Parser::RuleUnaryop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    _la = _input->LA(1);
    if (!(_la == C1Parser::Plus

    || _la == C1Parser::Minus)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool C1Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 13: return expSempred(dynamic_cast<ExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool C1Parser::expSempred(ExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> C1Parser::_decisionToDFA;
atn::PredictionContextCache C1Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN C1Parser::_atn;
std::vector<uint16_t> C1Parser::_serializedATN;

std::vector<std::string> C1Parser::_ruleNames = {
  "compilationUnit", "decl", "constdecl", "constdef", "vardecl", "vardef", 
  "funcdef", "block", "blockitem", "stmt", "lval", "cond", "relop", "exp", 
  "binop", "unaryop"
};

std::vector<std::string> C1Parser::_literalNames = {
  "", "','", "';'", "'='", "'['", "']'", "'{'", "'}'", "'('", "')'", "'if'", 
  "'else'", "'while'", "'const'", "'=='", "'!='", "'<'", "'>'", "'<='", 
  "'>='", "'+'", "'-'", "'*'", "'/'", "'%'", "'int'", "'void'"
};

std::vector<std::string> C1Parser::_symbolicNames = {
  "", "Comma", "SemiColon", "Assign", "LeftBracket", "RightBracket", "LeftBrace", 
  "RightBrace", "LeftParen", "RightParen", "If", "Else", "While", "Const", 
  "Equal", "NonEqual", "Less", "Greater", "LessEqual", "GreaterEqual", "Plus", 
  "Minus", "Multiply", "Divide", "Modulo", "Int", "Void", "Identifier", 
  "Number", "WhiteSpace", "LineComment", "BlockComment"
};

dfa::Vocabulary C1Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> C1Parser::_tokenNames;

C1Parser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x21, 0xea, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x3, 0x2, 
    0x3, 0x2, 0x6, 0x2, 0x25, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x26, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2d, 0xa, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x34, 0xa, 0x4, 0xc, 0x4, 
    0xe, 0x4, 0x37, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x7, 0x4, 0x3f, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x42, 0xb, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x46, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x4e, 0xa, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x56, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x59, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0x5d, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 
    0x63, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x66, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x6d, 0xa, 0x6, 0xc, 0x6, 0xe, 
    0x6, 0x70, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x74, 0xa, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x82, 0xa, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 
    0x8a, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x8d, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0x91, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x9b, 0xa, 0x9, 0xc, 0x9, 
    0xe, 0x9, 0x9e, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x5, 
    0xa, 0xa4, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xb7, 0xa, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0xc0, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xc8, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xd9, 
    0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x7, 0xf, 0xe1, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xe4, 0xb, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x2, 0x3, 0x1c, 0x12, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x2, 0x6, 0x3, 0x2, 0x10, 0x15, 0x3, 0x2, 0x16, 0x17, 0x3, 
    0x2, 0x18, 0x1a, 0x3, 0x2, 0x16, 0x1a, 0x2, 0xf8, 0x2, 0x24, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x6, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x5c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x73, 0x3, 0x2, 0x2, 0x2, 0xc, 0x90, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x92, 0x3, 0x2, 0x2, 0x2, 0x10, 0x98, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x14, 0xbf, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x18, 0xc9, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xd8, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x20, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x25, 0x5, 0xe, 0x8, 0x2, 0x23, 0x25, 0x5, 0x4, 0x3, 0x2, 0x24, 0x22, 
    0x3, 0x2, 0x2, 0x2, 0x24, 0x23, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x27, 0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x7, 0x2, 0x2, 
    0x3, 0x29, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2d, 0x5, 0x6, 0x4, 0x2, 
    0x2b, 0x2d, 0x5, 0xa, 0x6, 0x2, 0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 
    0x7, 0xf, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x1b, 0x2, 0x2, 0x30, 0x35, 0x5, 
    0x8, 0x5, 0x2, 0x31, 0x32, 0x7, 0x3, 0x2, 0x2, 0x32, 0x34, 0x5, 0x8, 
    0x5, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x34, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 
    0x36, 0x38, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x39, 0x7, 0x4, 0x2, 0x2, 0x39, 0x46, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 
    0x7, 0xf, 0x2, 0x2, 0x3b, 0x40, 0x5, 0x8, 0x5, 0x2, 0x3c, 0x3d, 0x7, 
    0x3, 0x2, 0x2, 0x3d, 0x3f, 0x5, 0x8, 0x5, 0x2, 0x3e, 0x3c, 0x3, 0x2, 
    0x2, 0x2, 0x3f, 0x42, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x7, 0x4, 0x2, 0x2, 0x44, 
    0x46, 0x3, 0x2, 0x2, 0x2, 0x45, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x45, 0x3a, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x7, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x7, 
    0x1d, 0x2, 0x2, 0x48, 0x49, 0x7, 0x5, 0x2, 0x2, 0x49, 0x5d, 0x5, 0x1c, 
    0xf, 0x2, 0x4a, 0x4b, 0x7, 0x1d, 0x2, 0x2, 0x4b, 0x4d, 0x7, 0x6, 0x2, 
    0x2, 0x4c, 0x4e, 0x5, 0x1c, 0xf, 0x2, 0x4d, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x50, 0x7, 0x7, 0x2, 0x2, 0x50, 0x51, 0x7, 0x5, 0x2, 0x2, 0x51, 0x52, 
    0x7, 0x8, 0x2, 0x2, 0x52, 0x57, 0x5, 0x1c, 0xf, 0x2, 0x53, 0x54, 0x7, 
    0x3, 0x2, 0x2, 0x54, 0x56, 0x5, 0x1c, 0xf, 0x2, 0x55, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x59, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 0x3, 0x2, 0x2, 0x2, 
    0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x9, 0x2, 0x2, 0x5b, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x47, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x4a, 
    0x3, 0x2, 0x2, 0x2, 0x5d, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 
    0x1b, 0x2, 0x2, 0x5f, 0x64, 0x5, 0xc, 0x7, 0x2, 0x60, 0x61, 0x7, 0x3, 
    0x2, 0x2, 0x61, 0x63, 0x5, 0xc, 0x7, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 
    0x2, 0x63, 0x66, 0x3, 0x2, 0x2, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x65, 0x3, 0x2, 0x2, 0x2, 0x65, 0x67, 0x3, 0x2, 0x2, 0x2, 0x66, 
    0x64, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x4, 0x2, 0x2, 0x68, 0x74, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x6e, 0x5, 0xc, 0x7, 0x2, 0x6a, 0x6b, 0x7, 
    0x3, 0x2, 0x2, 0x6b, 0x6d, 0x5, 0xc, 0x7, 0x2, 0x6c, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x6d, 0x70, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0x4, 0x2, 0x2, 0x72, 
    0x74, 0x3, 0x2, 0x2, 0x2, 0x73, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x73, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x74, 0xb, 0x3, 0x2, 0x2, 0x2, 0x75, 0x91, 0x7, 
    0x1d, 0x2, 0x2, 0x76, 0x77, 0x7, 0x1d, 0x2, 0x2, 0x77, 0x78, 0x7, 0x6, 
    0x2, 0x2, 0x78, 0x79, 0x5, 0x1c, 0xf, 0x2, 0x79, 0x7a, 0x7, 0x7, 0x2, 
    0x2, 0x7a, 0x91, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x1d, 0x2, 0x2, 
    0x7c, 0x7d, 0x7, 0x5, 0x2, 0x2, 0x7d, 0x91, 0x5, 0x1c, 0xf, 0x2, 0x7e, 
    0x7f, 0x7, 0x1d, 0x2, 0x2, 0x7f, 0x81, 0x7, 0x6, 0x2, 0x2, 0x80, 0x82, 
    0x5, 0x1c, 0xf, 0x2, 0x81, 0x80, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x7, 0x7, 
    0x2, 0x2, 0x84, 0x85, 0x7, 0x5, 0x2, 0x2, 0x85, 0x86, 0x7, 0x8, 0x2, 
    0x2, 0x86, 0x8b, 0x5, 0x1c, 0xf, 0x2, 0x87, 0x88, 0x7, 0x3, 0x2, 0x2, 
    0x88, 0x8a, 0x5, 0x1c, 0xf, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x8d, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 
    0x3, 0x2, 0x2, 0x2, 0x8c, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x9, 0x2, 0x2, 0x8f, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x75, 0x3, 0x2, 0x2, 0x2, 0x90, 0x76, 0x3, 0x2, 0x2, 
    0x2, 0x90, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x90, 0x7e, 0x3, 0x2, 0x2, 0x2, 
    0x91, 0xd, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x1c, 0x2, 0x2, 0x93, 
    0x94, 0x7, 0x1d, 0x2, 0x2, 0x94, 0x95, 0x7, 0xa, 0x2, 0x2, 0x95, 0x96, 
    0x7, 0xb, 0x2, 0x2, 0x96, 0x97, 0x5, 0x10, 0x9, 0x2, 0x97, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x98, 0x9c, 0x7, 0x8, 0x2, 0x2, 0x99, 0x9b, 0x5, 0x12, 
    0xa, 0x2, 0x9a, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9e, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x3, 0x2, 0x2, 0x2, 
    0x9d, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9f, 
    0xa0, 0x7, 0x9, 0x2, 0x2, 0xa0, 0x11, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa4, 
    0x5, 0x14, 0xb, 0x2, 0xa2, 0xa4, 0x5, 0x4, 0x3, 0x2, 0xa3, 0xa1, 0x3, 
    0x2, 0x2, 0x2, 0xa3, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0xa5, 0xa6, 0x5, 0x16, 0xc, 0x2, 0xa6, 0xa7, 0x7, 0x5, 0x2, 
    0x2, 0xa7, 0xa8, 0x5, 0x1c, 0xf, 0x2, 0xa8, 0xa9, 0x7, 0x4, 0x2, 0x2, 
    0xa9, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x1d, 0x2, 0x2, 0xab, 
    0xac, 0x7, 0xa, 0x2, 0x2, 0xac, 0xad, 0x7, 0xb, 0x2, 0x2, 0xad, 0xc0, 
    0x7, 0x4, 0x2, 0x2, 0xae, 0xc0, 0x5, 0x10, 0x9, 0x2, 0xaf, 0xb0, 0x7, 
    0xc, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0xa, 0x2, 0x2, 0xb1, 0xb2, 0x5, 0x18, 
    0xd, 0x2, 0xb2, 0xb3, 0x7, 0xb, 0x2, 0x2, 0xb3, 0xb6, 0x5, 0x14, 0xb, 
    0x2, 0xb4, 0xb5, 0x7, 0xd, 0x2, 0x2, 0xb5, 0xb7, 0x5, 0x14, 0xb, 0x2, 
    0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 
    0xc0, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x7, 0xe, 0x2, 0x2, 0xb9, 0xba, 
    0x7, 0xa, 0x2, 0x2, 0xba, 0xbb, 0x5, 0x18, 0xd, 0x2, 0xbb, 0xbc, 0x7, 
    0xb, 0x2, 0x2, 0xbc, 0xbd, 0x5, 0x14, 0xb, 0x2, 0xbd, 0xc0, 0x3, 0x2, 
    0x2, 0x2, 0xbe, 0xc0, 0x7, 0x4, 0x2, 0x2, 0xbf, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x15, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc8, 
    0x7, 0x1d, 0x2, 0x2, 0xc2, 0xc3, 0x7, 0x1d, 0x2, 0x2, 0xc3, 0xc4, 0x7, 
    0x6, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x1c, 0xf, 0x2, 0xc5, 0xc6, 0x7, 0x7, 
    0x2, 0x2, 0xc6, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc1, 0x3, 0x2, 0x2, 
    0x2, 0xc7, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0xc9, 0xca, 0x5, 0x1c, 0xf, 0x2, 0xca, 0xcb, 0x5, 0x1a, 0xe, 0x2, 0xcb, 
    0xcc, 0x5, 0x1c, 0xf, 0x2, 0xcc, 0x19, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 
    0x9, 0x2, 0x2, 0x2, 0xce, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x8, 
    0xf, 0x1, 0x2, 0xd0, 0xd1, 0x9, 0x3, 0x2, 0x2, 0xd1, 0xd9, 0x5, 0x1c, 
    0xf, 0x6, 0xd2, 0xd3, 0x7, 0xa, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0x1c, 0xf, 
    0x2, 0xd4, 0xd5, 0x7, 0xb, 0x2, 0x2, 0xd5, 0xd9, 0x3, 0x2, 0x2, 0x2, 
    0xd6, 0xd9, 0x5, 0x16, 0xc, 0x2, 0xd7, 0xd9, 0x7, 0x1e, 0x2, 0x2, 0xd8, 
    0xcf, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 
    0x3, 0x2, 0x2, 0x2, 0xd8, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xe2, 0x3, 
    0x2, 0x2, 0x2, 0xda, 0xdb, 0xc, 0x8, 0x2, 0x2, 0xdb, 0xdc, 0x9, 0x4, 
    0x2, 0x2, 0xdc, 0xe1, 0x5, 0x1c, 0xf, 0x9, 0xdd, 0xde, 0xc, 0x7, 0x2, 
    0x2, 0xde, 0xdf, 0x9, 0x3, 0x2, 0x2, 0xdf, 0xe1, 0x5, 0x1c, 0xf, 0x8, 
    0xe0, 0xda, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe1, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 
    0x3, 0x2, 0x2, 0x2, 0xe3, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe2, 0x3, 
    0x2, 0x2, 0x2, 0xe5, 0xe6, 0x9, 0x5, 0x2, 0x2, 0xe6, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0xe7, 0xe8, 0x9, 0x3, 0x2, 0x2, 0xe8, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x19, 0x24, 0x26, 0x2c, 0x35, 0x40, 0x45, 0x4d, 0x57, 0x5c, 0x64, 
    0x6e, 0x73, 0x81, 0x8b, 0x90, 0x9c, 0xa3, 0xb6, 0xbf, 0xc7, 0xd8, 0xe0, 
    0xe2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

C1Parser::Initializer C1Parser::_init;

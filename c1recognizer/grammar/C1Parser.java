// Generated from C1Parser.g4 by ANTLR 4.7
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class C1Parser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Comma=1, SemiColon=2, Assign=3, LeftBracket=4, RightBracket=5, LeftBrace=6, 
		RightBrace=7, LeftParen=8, RightParen=9, If=10, Else=11, While=12, Const=13, 
		Equal=14, NonEqual=15, Less=16, Greater=17, LessEqual=18, GreaterEqual=19, 
		Plus=20, Minus=21, Multiply=22, Divide=23, Modulo=24, Int=25, Void=26, 
		Identifier=27, Number=28, WhiteSpace=29, LineComment=30, BlockComment=31;
	public static final int
		RULE_compilationUnit = 0, RULE_decl = 1, RULE_constdecl = 2, RULE_constdef = 3, 
		RULE_vardecl = 4, RULE_vardef = 5, RULE_funcdef = 6, RULE_block = 7, RULE_blockitem = 8, 
		RULE_stmt = 9, RULE_lval = 10, RULE_cond = 11, RULE_relop = 12, RULE_exp = 13, 
		RULE_binop = 14, RULE_unaryop = 15;
	public static final String[] ruleNames = {
		"compilationUnit", "decl", "constdecl", "constdef", "vardecl", "vardef", 
		"funcdef", "block", "blockitem", "stmt", "lval", "cond", "relop", "exp", 
		"binop", "unaryop"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "','", "';'", "'='", "'['", "']'", "'{'", "'}'", "'('", "')'", "'if'", 
		"'else'", "'while'", "'const'", "'=='", "'!='", "'<'", "'>'", "'<='", 
		"'>='", "'+'", "'-'", "'*'", "'/'", "'%'", "'int'", "'void'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "Comma", "SemiColon", "Assign", "LeftBracket", "RightBracket", "LeftBrace", 
		"RightBrace", "LeftParen", "RightParen", "If", "Else", "While", "Const", 
		"Equal", "NonEqual", "Less", "Greater", "LessEqual", "GreaterEqual", "Plus", 
		"Minus", "Multiply", "Divide", "Modulo", "Int", "Void", "Identifier", 
		"Number", "WhiteSpace", "LineComment", "BlockComment"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "C1Parser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public C1Parser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class CompilationUnitContext extends ParserRuleContext {
		public List<DeclContext> decl() {
			return getRuleContexts(DeclContext.class);
		}
		public DeclContext decl(int i) {
			return getRuleContext(DeclContext.class,i);
		}
		public List<FuncdefContext> funcdef() {
			return getRuleContexts(FuncdefContext.class);
		}
		public FuncdefContext funcdef(int i) {
			return getRuleContext(FuncdefContext.class,i);
		}
		public CompilationUnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compilationUnit; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterCompilationUnit(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitCompilationUnit(this);
		}
	}

	public final CompilationUnitContext compilationUnit() throws RecognitionException {
		CompilationUnitContext _localctx = new CompilationUnitContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_compilationUnit);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(34); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(34);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case Const:
				case Int:
					{
					setState(32);
					decl();
					}
					break;
				case Void:
					{
					setState(33);
					funcdef();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(36); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Const) | (1L << Int) | (1L << Void))) != 0) );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclContext extends ParserRuleContext {
		public ConstdeclContext constdecl() {
			return getRuleContext(ConstdeclContext.class,0);
		}
		public VardeclContext vardecl() {
			return getRuleContext(VardeclContext.class,0);
		}
		public DeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_decl; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterDecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitDecl(this);
		}
	}

	public final DeclContext decl() throws RecognitionException {
		DeclContext _localctx = new DeclContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_decl);
		try {
			setState(40);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Const:
				enterOuterAlt(_localctx, 1);
				{
				setState(38);
				constdecl();
				}
				break;
			case Int:
				enterOuterAlt(_localctx, 2);
				{
				setState(39);
				vardecl();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstdeclContext extends ParserRuleContext {
		public TerminalNode Const() { return getToken(C1Parser.Const, 0); }
		public TerminalNode Int() { return getToken(C1Parser.Int, 0); }
		public List<ConstdefContext> constdef() {
			return getRuleContexts(ConstdefContext.class);
		}
		public ConstdefContext constdef(int i) {
			return getRuleContext(ConstdefContext.class,i);
		}
		public TerminalNode SemiColon() { return getToken(C1Parser.SemiColon, 0); }
		public List<TerminalNode> Comma() { return getTokens(C1Parser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(C1Parser.Comma, i);
		}
		public ConstdeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constdecl; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterConstdecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitConstdecl(this);
		}
	}

	public final ConstdeclContext constdecl() throws RecognitionException {
		ConstdeclContext _localctx = new ConstdeclContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_constdecl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(42);
			match(Const);
			setState(43);
			match(Int);
			setState(44);
			constdef();
			setState(49);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(45);
				match(Comma);
				setState(46);
				constdef();
				}
				}
				setState(51);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(52);
			match(SemiColon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstdefContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(C1Parser.Identifier, 0); }
		public TerminalNode Assign() { return getToken(C1Parser.Assign, 0); }
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode LeftBracket() { return getToken(C1Parser.LeftBracket, 0); }
		public TerminalNode RightBracket() { return getToken(C1Parser.RightBracket, 0); }
		public TerminalNode LeftBrace() { return getToken(C1Parser.LeftBrace, 0); }
		public TerminalNode RightBrace() { return getToken(C1Parser.RightBrace, 0); }
		public List<TerminalNode> Comma() { return getTokens(C1Parser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(C1Parser.Comma, i);
		}
		public ConstdefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constdef; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterConstdef(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitConstdef(this);
		}
	}

	public final ConstdefContext constdef() throws RecognitionException {
		ConstdefContext _localctx = new ConstdefContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_constdef);
		int _la;
		try {
			setState(75);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(54);
				match(Identifier);
				setState(55);
				match(Assign);
				setState(56);
				exp(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(57);
				match(Identifier);
				setState(58);
				match(LeftBracket);
				setState(60);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LeftParen) | (1L << Plus) | (1L << Minus) | (1L << Identifier) | (1L << Number))) != 0)) {
					{
					setState(59);
					exp(0);
					}
				}

				setState(62);
				match(RightBracket);
				setState(63);
				match(Assign);
				setState(64);
				match(LeftBrace);
				setState(65);
				exp(0);
				setState(70);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==Comma) {
					{
					{
					setState(66);
					match(Comma);
					setState(67);
					exp(0);
					}
					}
					setState(72);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(73);
				match(RightBrace);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VardeclContext extends ParserRuleContext {
		public TerminalNode Int() { return getToken(C1Parser.Int, 0); }
		public List<VardefContext> vardef() {
			return getRuleContexts(VardefContext.class);
		}
		public VardefContext vardef(int i) {
			return getRuleContext(VardefContext.class,i);
		}
		public TerminalNode SemiColon() { return getToken(C1Parser.SemiColon, 0); }
		public List<TerminalNode> Comma() { return getTokens(C1Parser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(C1Parser.Comma, i);
		}
		public VardeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vardecl; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterVardecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitVardecl(this);
		}
	}

	public final VardeclContext vardecl() throws RecognitionException {
		VardeclContext _localctx = new VardeclContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_vardecl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(77);
			match(Int);
			setState(78);
			vardef();
			setState(83);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(79);
				match(Comma);
				setState(80);
				vardef();
				}
				}
				setState(85);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(86);
			match(SemiColon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VardefContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(C1Parser.Identifier, 0); }
		public TerminalNode LeftBracket() { return getToken(C1Parser.LeftBracket, 0); }
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode RightBracket() { return getToken(C1Parser.RightBracket, 0); }
		public TerminalNode Assign() { return getToken(C1Parser.Assign, 0); }
		public TerminalNode LeftBrace() { return getToken(C1Parser.LeftBrace, 0); }
		public TerminalNode RightBrace() { return getToken(C1Parser.RightBrace, 0); }
		public List<TerminalNode> Comma() { return getTokens(C1Parser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(C1Parser.Comma, i);
		}
		public VardefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vardef; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterVardef(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitVardef(this);
		}
	}

	public final VardefContext vardef() throws RecognitionException {
		VardefContext _localctx = new VardefContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_vardef);
		int _la;
		try {
			setState(115);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(88);
				match(Identifier);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(89);
				match(Identifier);
				setState(90);
				match(LeftBracket);
				setState(91);
				exp(0);
				setState(92);
				match(RightBracket);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(94);
				match(Identifier);
				setState(95);
				match(Assign);
				setState(96);
				exp(0);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(97);
				match(Identifier);
				setState(98);
				match(LeftBracket);
				setState(100);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LeftParen) | (1L << Plus) | (1L << Minus) | (1L << Identifier) | (1L << Number))) != 0)) {
					{
					setState(99);
					exp(0);
					}
				}

				setState(102);
				match(RightBracket);
				setState(103);
				match(Assign);
				setState(104);
				match(LeftBrace);
				setState(105);
				exp(0);
				setState(110);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==Comma) {
					{
					{
					setState(106);
					match(Comma);
					setState(107);
					exp(0);
					}
					}
					setState(112);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(113);
				match(RightBrace);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FuncdefContext extends ParserRuleContext {
		public TerminalNode Void() { return getToken(C1Parser.Void, 0); }
		public TerminalNode Identifier() { return getToken(C1Parser.Identifier, 0); }
		public TerminalNode LeftParen() { return getToken(C1Parser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(C1Parser.RightParen, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public FuncdefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcdef; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterFuncdef(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitFuncdef(this);
		}
	}

	public final FuncdefContext funcdef() throws RecognitionException {
		FuncdefContext _localctx = new FuncdefContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_funcdef);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(117);
			match(Void);
			setState(118);
			match(Identifier);
			setState(119);
			match(LeftParen);
			setState(120);
			match(RightParen);
			setState(121);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockContext extends ParserRuleContext {
		public TerminalNode LeftBrace() { return getToken(C1Parser.LeftBrace, 0); }
		public TerminalNode RightBrace() { return getToken(C1Parser.RightBrace, 0); }
		public List<BlockitemContext> blockitem() {
			return getRuleContexts(BlockitemContext.class);
		}
		public BlockitemContext blockitem(int i) {
			return getRuleContext(BlockitemContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitBlock(this);
		}
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(123);
			match(LeftBrace);
			setState(127);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << SemiColon) | (1L << LeftBrace) | (1L << If) | (1L << While) | (1L << Const) | (1L << Int) | (1L << Identifier))) != 0)) {
				{
				{
				setState(124);
				blockitem();
				}
				}
				setState(129);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(130);
			match(RightBrace);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockitemContext extends ParserRuleContext {
		public DeclContext decl() {
			return getRuleContext(DeclContext.class,0);
		}
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public BlockitemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockitem; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterBlockitem(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitBlockitem(this);
		}
	}

	public final BlockitemContext blockitem() throws RecognitionException {
		BlockitemContext _localctx = new BlockitemContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_blockitem);
		try {
			setState(134);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Const:
			case Int:
				enterOuterAlt(_localctx, 1);
				{
				setState(132);
				decl();
				}
				break;
			case SemiColon:
			case LeftBrace:
			case If:
			case While:
			case Identifier:
				enterOuterAlt(_localctx, 2);
				{
				setState(133);
				stmt();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StmtContext extends ParserRuleContext {
		public LvalContext lval() {
			return getRuleContext(LvalContext.class,0);
		}
		public TerminalNode Assign() { return getToken(C1Parser.Assign, 0); }
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public TerminalNode SemiColon() { return getToken(C1Parser.SemiColon, 0); }
		public TerminalNode Identifier() { return getToken(C1Parser.Identifier, 0); }
		public TerminalNode LeftParen() { return getToken(C1Parser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(C1Parser.RightParen, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode If() { return getToken(C1Parser.If, 0); }
		public CondContext cond() {
			return getRuleContext(CondContext.class,0);
		}
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public TerminalNode Else() { return getToken(C1Parser.Else, 0); }
		public TerminalNode While() { return getToken(C1Parser.While, 0); }
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterStmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitStmt(this);
		}
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_stmt);
		try {
			setState(162);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(136);
				lval();
				setState(137);
				match(Assign);
				setState(138);
				exp(0);
				setState(139);
				match(SemiColon);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(141);
				match(Identifier);
				setState(142);
				match(LeftParen);
				setState(143);
				match(RightParen);
				setState(144);
				match(SemiColon);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(145);
				block();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(146);
				match(If);
				setState(147);
				match(LeftParen);
				setState(148);
				cond();
				setState(149);
				match(RightParen);
				setState(150);
				stmt();
				setState(153);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
				case 1:
					{
					setState(151);
					match(Else);
					setState(152);
					stmt();
					}
					break;
				}
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(155);
				match(While);
				setState(156);
				match(LeftParen);
				setState(157);
				cond();
				setState(158);
				match(RightParen);
				setState(159);
				stmt();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(161);
				match(SemiColon);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LvalContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(C1Parser.Identifier, 0); }
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public LvalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lval; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterLval(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitLval(this);
		}
	}

	public final LvalContext lval() throws RecognitionException {
		LvalContext _localctx = new LvalContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_lval);
		try {
			setState(170);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(164);
				match(Identifier);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(165);
				match(Identifier);
				setState(166);
				match(LeftBracket);
				setState(167);
				exp(0);
				setState(168);
				match(RightBracket);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CondContext extends ParserRuleContext {
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public RelopContext relop() {
			return getRuleContext(RelopContext.class,0);
		}
		public CondContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_cond; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterCond(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitCond(this);
		}
	}

	public final CondContext cond() throws RecognitionException {
		CondContext _localctx = new CondContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_cond);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(172);
			exp(0);
			setState(173);
			relop();
			setState(174);
			exp(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RelopContext extends ParserRuleContext {
		public TerminalNode Equal() { return getToken(C1Parser.Equal, 0); }
		public TerminalNode NonEqual() { return getToken(C1Parser.NonEqual, 0); }
		public TerminalNode Less() { return getToken(C1Parser.Less, 0); }
		public TerminalNode Greater() { return getToken(C1Parser.Greater, 0); }
		public TerminalNode LessEqual() { return getToken(C1Parser.LessEqual, 0); }
		public TerminalNode GreaterEqual() { return getToken(C1Parser.GreaterEqual, 0); }
		public RelopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterRelop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitRelop(this);
		}
	}

	public final RelopContext relop() throws RecognitionException {
		RelopContext _localctx = new RelopContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_relop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(176);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Equal) | (1L << NonEqual) | (1L << Less) | (1L << Greater) | (1L << LessEqual) | (1L << GreaterEqual))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpContext extends ParserRuleContext {
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode Plus() { return getToken(C1Parser.Plus, 0); }
		public TerminalNode Minus() { return getToken(C1Parser.Minus, 0); }
		public TerminalNode LeftParen() { return getToken(C1Parser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(C1Parser.RightParen, 0); }
		public LvalContext lval() {
			return getRuleContext(LvalContext.class,0);
		}
		public TerminalNode Number() { return getToken(C1Parser.Number, 0); }
		public TerminalNode Multiply() { return getToken(C1Parser.Multiply, 0); }
		public TerminalNode Divide() { return getToken(C1Parser.Divide, 0); }
		public TerminalNode Modulo() { return getToken(C1Parser.Modulo, 0); }
		public ExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exp; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterExp(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitExp(this);
		}
	}

	public final ExpContext exp() throws RecognitionException {
		return exp(0);
	}

	private ExpContext exp(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpContext _localctx = new ExpContext(_ctx, _parentState);
		ExpContext _prevctx = _localctx;
		int _startState = 26;
		enterRecursionRule(_localctx, 26, RULE_exp, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(187);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Plus:
			case Minus:
				{
				setState(179);
				_la = _input.LA(1);
				if ( !(_la==Plus || _la==Minus) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(180);
				exp(4);
				}
				break;
			case LeftParen:
				{
				setState(181);
				match(LeftParen);
				setState(182);
				exp(0);
				setState(183);
				match(RightParen);
				}
				break;
			case Identifier:
				{
				setState(185);
				lval();
				}
				break;
			case Number:
				{
				setState(186);
				match(Number);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(197);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(195);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
					case 1:
						{
						_localctx = new ExpContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_exp);
						setState(189);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(190);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Multiply) | (1L << Divide) | (1L << Modulo))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(191);
						exp(7);
						}
						break;
					case 2:
						{
						_localctx = new ExpContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_exp);
						setState(192);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(193);
						_la = _input.LA(1);
						if ( !(_la==Plus || _la==Minus) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(194);
						exp(6);
						}
						break;
					}
					} 
				}
				setState(199);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class BinopContext extends ParserRuleContext {
		public TerminalNode Plus() { return getToken(C1Parser.Plus, 0); }
		public TerminalNode Minus() { return getToken(C1Parser.Minus, 0); }
		public TerminalNode Multiply() { return getToken(C1Parser.Multiply, 0); }
		public TerminalNode Divide() { return getToken(C1Parser.Divide, 0); }
		public TerminalNode Modulo() { return getToken(C1Parser.Modulo, 0); }
		public BinopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_binop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterBinop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitBinop(this);
		}
	}

	public final BinopContext binop() throws RecognitionException {
		BinopContext _localctx = new BinopContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_binop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(200);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Plus) | (1L << Minus) | (1L << Multiply) | (1L << Divide) | (1L << Modulo))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnaryopContext extends ParserRuleContext {
		public TerminalNode Plus() { return getToken(C1Parser.Plus, 0); }
		public TerminalNode Minus() { return getToken(C1Parser.Minus, 0); }
		public UnaryopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unaryop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).enterUnaryop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof C1ParserListener ) ((C1ParserListener)listener).exitUnaryop(this);
		}
	}

	public final UnaryopContext unaryop() throws RecognitionException {
		UnaryopContext _localctx = new UnaryopContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_unaryop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(202);
			_la = _input.LA(1);
			if ( !(_la==Plus || _la==Minus) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 13:
			return exp_sempred((ExpContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean exp_sempred(ExpContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 6);
		case 1:
			return precpred(_ctx, 5);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3!\u00cf\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\3\2\3\2\6"+
		"\2%\n\2\r\2\16\2&\3\3\3\3\5\3+\n\3\3\4\3\4\3\4\3\4\3\4\7\4\62\n\4\f\4"+
		"\16\4\65\13\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\5\5?\n\5\3\5\3\5\3\5\3\5"+
		"\3\5\3\5\7\5G\n\5\f\5\16\5J\13\5\3\5\3\5\5\5N\n\5\3\6\3\6\3\6\3\6\7\6"+
		"T\n\6\f\6\16\6W\13\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3"+
		"\7\3\7\5\7g\n\7\3\7\3\7\3\7\3\7\3\7\3\7\7\7o\n\7\f\7\16\7r\13\7\3\7\3"+
		"\7\5\7v\n\7\3\b\3\b\3\b\3\b\3\b\3\b\3\t\3\t\7\t\u0080\n\t\f\t\16\t\u0083"+
		"\13\t\3\t\3\t\3\n\3\n\5\n\u0089\n\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\5\13\u009c\n\13\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\3\13\5\13\u00a5\n\13\3\f\3\f\3\f\3\f\3\f\3\f"+
		"\5\f\u00ad\n\f\3\r\3\r\3\r\3\r\3\16\3\16\3\17\3\17\3\17\3\17\3\17\3\17"+
		"\3\17\3\17\3\17\5\17\u00be\n\17\3\17\3\17\3\17\3\17\3\17\3\17\7\17\u00c6"+
		"\n\17\f\17\16\17\u00c9\13\17\3\20\3\20\3\21\3\21\3\21\2\3\34\22\2\4\6"+
		"\b\n\f\16\20\22\24\26\30\32\34\36 \2\6\3\2\20\25\3\2\26\27\3\2\30\32\3"+
		"\2\26\32\2\u00d9\2$\3\2\2\2\4*\3\2\2\2\6,\3\2\2\2\bM\3\2\2\2\nO\3\2\2"+
		"\2\fu\3\2\2\2\16w\3\2\2\2\20}\3\2\2\2\22\u0088\3\2\2\2\24\u00a4\3\2\2"+
		"\2\26\u00ac\3\2\2\2\30\u00ae\3\2\2\2\32\u00b2\3\2\2\2\34\u00bd\3\2\2\2"+
		"\36\u00ca\3\2\2\2 \u00cc\3\2\2\2\"%\5\4\3\2#%\5\16\b\2$\"\3\2\2\2$#\3"+
		"\2\2\2%&\3\2\2\2&$\3\2\2\2&\'\3\2\2\2\'\3\3\2\2\2(+\5\6\4\2)+\5\n\6\2"+
		"*(\3\2\2\2*)\3\2\2\2+\5\3\2\2\2,-\7\17\2\2-.\7\33\2\2.\63\5\b\5\2/\60"+
		"\7\3\2\2\60\62\5\b\5\2\61/\3\2\2\2\62\65\3\2\2\2\63\61\3\2\2\2\63\64\3"+
		"\2\2\2\64\66\3\2\2\2\65\63\3\2\2\2\66\67\7\4\2\2\67\7\3\2\2\289\7\35\2"+
		"\29:\7\5\2\2:N\5\34\17\2;<\7\35\2\2<>\7\6\2\2=?\5\34\17\2>=\3\2\2\2>?"+
		"\3\2\2\2?@\3\2\2\2@A\7\7\2\2AB\7\5\2\2BC\7\b\2\2CH\5\34\17\2DE\7\3\2\2"+
		"EG\5\34\17\2FD\3\2\2\2GJ\3\2\2\2HF\3\2\2\2HI\3\2\2\2IK\3\2\2\2JH\3\2\2"+
		"\2KL\7\t\2\2LN\3\2\2\2M8\3\2\2\2M;\3\2\2\2N\t\3\2\2\2OP\7\33\2\2PU\5\f"+
		"\7\2QR\7\3\2\2RT\5\f\7\2SQ\3\2\2\2TW\3\2\2\2US\3\2\2\2UV\3\2\2\2VX\3\2"+
		"\2\2WU\3\2\2\2XY\7\4\2\2Y\13\3\2\2\2Zv\7\35\2\2[\\\7\35\2\2\\]\7\6\2\2"+
		"]^\5\34\17\2^_\7\7\2\2_v\3\2\2\2`a\7\35\2\2ab\7\5\2\2bv\5\34\17\2cd\7"+
		"\35\2\2df\7\6\2\2eg\5\34\17\2fe\3\2\2\2fg\3\2\2\2gh\3\2\2\2hi\7\7\2\2"+
		"ij\7\5\2\2jk\7\b\2\2kp\5\34\17\2lm\7\3\2\2mo\5\34\17\2nl\3\2\2\2or\3\2"+
		"\2\2pn\3\2\2\2pq\3\2\2\2qs\3\2\2\2rp\3\2\2\2st\7\t\2\2tv\3\2\2\2uZ\3\2"+
		"\2\2u[\3\2\2\2u`\3\2\2\2uc\3\2\2\2v\r\3\2\2\2wx\7\34\2\2xy\7\35\2\2yz"+
		"\7\n\2\2z{\7\13\2\2{|\5\20\t\2|\17\3\2\2\2}\u0081\7\b\2\2~\u0080\5\22"+
		"\n\2\177~\3\2\2\2\u0080\u0083\3\2\2\2\u0081\177\3\2\2\2\u0081\u0082\3"+
		"\2\2\2\u0082\u0084\3\2\2\2\u0083\u0081\3\2\2\2\u0084\u0085\7\t\2\2\u0085"+
		"\21\3\2\2\2\u0086\u0089\5\4\3\2\u0087\u0089\5\24\13\2\u0088\u0086\3\2"+
		"\2\2\u0088\u0087\3\2\2\2\u0089\23\3\2\2\2\u008a\u008b\5\26\f\2\u008b\u008c"+
		"\7\5\2\2\u008c\u008d\5\34\17\2\u008d\u008e\7\4\2\2\u008e\u00a5\3\2\2\2"+
		"\u008f\u0090\7\35\2\2\u0090\u0091\7\n\2\2\u0091\u0092\7\13\2\2\u0092\u00a5"+
		"\7\4\2\2\u0093\u00a5\5\20\t\2\u0094\u0095\7\f\2\2\u0095\u0096\7\n\2\2"+
		"\u0096\u0097\5\30\r\2\u0097\u0098\7\13\2\2\u0098\u009b\5\24\13\2\u0099"+
		"\u009a\7\r\2\2\u009a\u009c\5\24\13\2\u009b\u0099\3\2\2\2\u009b\u009c\3"+
		"\2\2\2\u009c\u00a5\3\2\2\2\u009d\u009e\7\16\2\2\u009e\u009f\7\n\2\2\u009f"+
		"\u00a0\5\30\r\2\u00a0\u00a1\7\13\2\2\u00a1\u00a2\5\24\13\2\u00a2\u00a5"+
		"\3\2\2\2\u00a3\u00a5\7\4\2\2\u00a4\u008a\3\2\2\2\u00a4\u008f\3\2\2\2\u00a4"+
		"\u0093\3\2\2\2\u00a4\u0094\3\2\2\2\u00a4\u009d\3\2\2\2\u00a4\u00a3\3\2"+
		"\2\2\u00a5\25\3\2\2\2\u00a6\u00ad\7\35\2\2\u00a7\u00a8\7\35\2\2\u00a8"+
		"\u00a9\7\6\2\2\u00a9\u00aa\5\34\17\2\u00aa\u00ab\7\7\2\2\u00ab\u00ad\3"+
		"\2\2\2\u00ac\u00a6\3\2\2\2\u00ac\u00a7\3\2\2\2\u00ad\27\3\2\2\2\u00ae"+
		"\u00af\5\34\17\2\u00af\u00b0\5\32\16\2\u00b0\u00b1\5\34\17\2\u00b1\31"+
		"\3\2\2\2\u00b2\u00b3\t\2\2\2\u00b3\33\3\2\2\2\u00b4\u00b5\b\17\1\2\u00b5"+
		"\u00b6\t\3\2\2\u00b6\u00be\5\34\17\6\u00b7\u00b8\7\n\2\2\u00b8\u00b9\5"+
		"\34\17\2\u00b9\u00ba\7\13\2\2\u00ba\u00be\3\2\2\2\u00bb\u00be\5\26\f\2"+
		"\u00bc\u00be\7\36\2\2\u00bd\u00b4\3\2\2\2\u00bd\u00b7\3\2\2\2\u00bd\u00bb"+
		"\3\2\2\2\u00bd\u00bc\3\2\2\2\u00be\u00c7\3\2\2\2\u00bf\u00c0\f\b\2\2\u00c0"+
		"\u00c1\t\4\2\2\u00c1\u00c6\5\34\17\t\u00c2\u00c3\f\7\2\2\u00c3\u00c4\t"+
		"\3\2\2\u00c4\u00c6\5\34\17\b\u00c5\u00bf\3\2\2\2\u00c5\u00c2\3\2\2\2\u00c6"+
		"\u00c9\3\2\2\2\u00c7\u00c5\3\2\2\2\u00c7\u00c8\3\2\2\2\u00c8\35\3\2\2"+
		"\2\u00c9\u00c7\3\2\2\2\u00ca\u00cb\t\5\2\2\u00cb\37\3\2\2\2\u00cc\u00cd"+
		"\t\3\2\2\u00cd!\3\2\2\2\25$&*\63>HMUfpu\u0081\u0088\u009b\u00a4\u00ac"+
		"\u00bd\u00c5\u00c7";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
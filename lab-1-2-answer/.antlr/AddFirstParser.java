// Generated from /media/songchaow/Windows/Users/Lenovo/OneDrive/大三上/Compilation Theory/PB15000102/lab-1-2-answer/AddFirst.g4 by ANTLR 4.7
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class AddFirstParser extends Parser {
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
		RULE_e = 0;
	public static final String[] ruleNames = {
		"e"
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
	public String getGrammarFileName() { return "AddFirst.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public AddFirstParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class EContext extends ParserRuleContext {
		public EContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_e; }
	 
		public EContext() { }
		public void copyFrom(EContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class NumberContext extends EContext {
		public TerminalNode Number() { return getToken(AddFirstParser.Number, 0); }
		public NumberContext(EContext ctx) { copyFrom(ctx); }
	}
	public static class MultContext extends EContext {
		public List<EContext> e() {
			return getRuleContexts(EContext.class);
		}
		public EContext e(int i) {
			return getRuleContext(EContext.class,i);
		}
		public TerminalNode Multiply() { return getToken(AddFirstParser.Multiply, 0); }
		public MultContext(EContext ctx) { copyFrom(ctx); }
	}
	public static class PlusContext extends EContext {
		public List<EContext> e() {
			return getRuleContexts(EContext.class);
		}
		public EContext e(int i) {
			return getRuleContext(EContext.class,i);
		}
		public TerminalNode Plus() { return getToken(AddFirstParser.Plus, 0); }
		public PlusContext(EContext ctx) { copyFrom(ctx); }
	}

	public final EContext e() throws RecognitionException {
		return e(0);
	}

	private EContext e(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		EContext _localctx = new EContext(_ctx, _parentState);
		EContext _prevctx = _localctx;
		int _startState = 0;
		enterRecursionRule(_localctx, 0, RULE_e, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new NumberContext(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(3);
			match(Number);
			}
			_ctx.stop = _input.LT(-1);
			setState(13);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(11);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
					case 1:
						{
						_localctx = new PlusContext(new EContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_e);
						setState(5);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(6);
						match(Plus);
						setState(7);
						e(4);
						}
						break;
					case 2:
						{
						_localctx = new MultContext(new EContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_e);
						setState(8);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(9);
						match(Multiply);
						setState(10);
						e(3);
						}
						break;
					}
					} 
				}
				setState(15);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
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

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 0:
			return e_sempred((EContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean e_sempred(EContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 3);
		case 1:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3!\23\4\2\t\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\7\2\16\n\2\f\2\16\2\21\13\2\3\2\2\3\2\3"+
		"\2\2\2\2\23\2\4\3\2\2\2\4\5\b\2\1\2\5\6\7\36\2\2\6\17\3\2\2\2\7\b\f\5"+
		"\2\2\b\t\7\26\2\2\t\16\5\2\2\6\n\13\f\4\2\2\13\f\7\30\2\2\f\16\5\2\2\5"+
		"\r\7\3\2\2\2\r\n\3\2\2\2\16\21\3\2\2\2\17\r\3\2\2\2\17\20\3\2\2\2\20\3"+
		"\3\2\2\2\21\17\3\2\2\2\4\r\17";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
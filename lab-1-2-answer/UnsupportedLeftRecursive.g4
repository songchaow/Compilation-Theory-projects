grammar UnsupportedLeftRecursive;



Comma: ',';
SemiColon: ';';
Assign: '=';
LeftBracket: '[';
RightBracket: ']';
LeftBrace: '{';
RightBrace: '}';
LeftParen: '(';
RightParen: ')';

If: 'if';
Else: 'else';
While: 'while';
Const: 'const';
Equal: '==';
NonEqual: '!=';
Less: '<';
Greater: '>';
LessEqual: '<=';
GreaterEqual: '>=';

Plus: '+' ;
Minus: '-' ;
Multiply: '*' ;
Divide: '/' ;
Modulo: '%' ;

Int: 'int';
Void: 'void';

Identifier: [a-zA-Z_][a-zA-Z0-9_]*;
Number: [0-9]+ | '0x' [0-9a-fA-F]+ ;

WhiteSpace: [ \t\r\n]+ -> skip;
LineComment: '//'  ~[\r\n]* '\r'? '\n' -> skip ;
BlockComment: '/*' .*? '*/' -> skip;

// indirect left-recursion:
e: sub Number
    | Number;
sub: e | Identifier;

// hidden left-recursion
f: sub2 f
    | Number;
sub2: Plus*;
grammar AddFirst;



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

e: e '+' e
    | e '*' e
    | Number;
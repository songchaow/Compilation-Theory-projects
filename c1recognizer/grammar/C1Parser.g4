parser grammar C1Parser;
options { tokenVocab = C1Lexer; }

compilationUnit: (funcdef | decl)+ EOF;
decl: constdecl | vardecl;
constdecl: Const Int constdef (Comma constdef)* SemiColon
    | Const constdef (Comma constdef)* SemiColon // implicit type declaration, with warning
    ; 
constdef: Identifier Assign exp
    | Identifier LeftBracket exp? RightBracket Assign LeftBrace exp (Comma exp)* RightBrace
    ;
vardecl: Int vardef (Comma vardef)* SemiColon
    | vardef (Comma vardef)* SemiColon // implicit type declaration, with warning
    ;
vardef: Identifier 
    | Identifier LeftBracket exp RightBracket
    | Identifier Assign exp
    | Identifier LeftBracket exp? RightBracket Assign LeftBrace exp (Comma exp)* RightBrace
    ;
funcdef: Void Identifier LeftParen RightParen block;
block: LeftBrace blockitem* RightBrace;
blockitem: stmt | decl;
stmt: lval Assign exp SemiColon
    | Identifier LeftParen RightParen SemiColon
    | block
    | If LeftParen cond RightParen stmt (Else stmt)?
    | While LeftParen cond RightParen stmt
    | SemiColon
    ;
lval: Identifier | Identifier '[' exp ']';
cond: exp relop exp;
relop: Equal | NonEqual | Less | Greater | LessEqual | GreaterEqual | LessEqual;
exp:
    exp (Multiply | Divide | Modulo) exp
    | exp (Plus | Minus) exp
    | (Plus | Minus) exp
    | LeftParen exp RightParen
    | lval
    | Number
;
binop: Plus | Minus | Multiply | Divide | Modulo;
unaryop: Plus | Minus;

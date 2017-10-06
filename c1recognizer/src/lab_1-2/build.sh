cd ../../grammar/
java org.antlr.v4.Tool C1Lexer.g4
java org.antlr.v4.Tool C1Parser.g4
javac *.java
java org.antlr.v4.gui.TestRig C1 compilationUnit -gui ../test/test_cases/simple.c1
cd ../src/lab_1-2
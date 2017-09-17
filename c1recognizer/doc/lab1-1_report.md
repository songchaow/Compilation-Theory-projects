 # Lab 1-1 Report

> PB15000102 王嵩超

## Purpose

To build a lexical analyzer via writing a grammar specification file used by ANTLR, and analyze some source codes of `C1` language.

撰写和提交介绍课程实验的分析、设计和测试方面的报告。

## Analyze

Part of the grammar specification file has already been provided.

After reading the file, I found there was merely three more tasks to accomplish: to design the patterns for items in `tokens` and to add patterns for comments. And finally, to design some test `C1` source files(some with errors) to examine the correctness of the parser(analyzer) generated.

## Designation

Line comments always start with `//`, and end at the newline, no matter what characters there are after `//`.

But block comments are different. They start with `/*`, and end when encounter `*/`.

So the contents of line comments will contain only one `//`. Here is the designation of regular expression:

```python
'//'  ~[\r\n]* '\r'? '\n'
```

The regular expression to match block comments is shown below.

```python
'/*' .*? '*/'
```

## Tests

First, we have to run ANTLR to generate the source code of the analyzer.

Then we build the analyzer. Finally we use `grun` to start the analyzer and analyze some tests.

> In lab 1-1, we're only required to generate the lexer, not the parser. So in `g4` file, there is a `lexer` prefix before `grammar`.
>
> In this case, we have to set `startRuleName` to `tokens` in the command-line arguments.

In the first 2 cases, I wrote simple `C1` codes but with two different line endings. These codes were analyzed properly.

In the third case, I made 2 errors:

- There is a identifier named `32xdada`.

- There is a identifier named `ada&`.

  However, the analyzer didn't report the first error, but processed it as a number(32) and another identifier(`data`) instead.

  The analyzer reported the second error, and continued to parse the text after `&`.

The parse results are shwon below.

```
line 13:12 token recognition error at: '&'
[@0,77:79='int',<'int'>,3:0]
[@1,81:84='main',<Identifier>,3:4]
[@2,85:85='(',<'('>,3:8]
[@3,86:86=')',<')'>,3:9]
[@4,89:89='{',<'{'>,4:0]
[@5,143:145='int',<'int'>,7:6]
[@6,147:147='j',<Identifier>,7:10]
[@7,149:149='=',<'='>,7:12]
[@8,151:151='2',<Number>,7:14]
[@9,152:152=';',<';'>,7:15]
[@10,180:182='int',<'int'>,8:4]
[@11,184:184='i',<Identifier>,8:8]
[@12,186:186='=',<'='>,8:10]
[@13,188:188='1',<Number>,8:12]
[@14,189:189=';',<';'>,8:13]
[@15,240:242='int',<'int'>,10:4]
[@16,244:245='32',<Number>,10:8]
[@17,246:250='xdada',<Identifier>,10:10]
[@18,252:252='=',<'='>,10:16]
[@19,254:255='25',<Number>,10:18]
[@20,256:256=';',<';'>,10:20]
[@21,375:377='int',<'int'>,13:4]
[@22,379:382='dada',<Identifier>,13:8]
[@23,385:385='=',<'='>,13:14]
[@24,387:388='24',<Number>,13:16]
[@25,389:389=';',<';'>,13:18]
[@26,396:398='int',<'int'>,14:4]
[@27,400:403='haha',<Identifier>,14:8]
[@28,405:405='=',<'='>,14:13]
[@29,407:410='0x25',<Number>,14:15]
[@30,411:411='+',<'+'>,14:19]
[@31,412:413='27',<Number>,14:20]
[@32,414:414=';',<';'>,14:22]
[@33,417:417='}',<'}'>,15:0]
[@34,418:417='<EOF>',<EOF>,15:1]
```


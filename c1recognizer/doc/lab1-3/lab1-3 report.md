 # Lab 1-3 Report

> PB15000102 王嵩超

# 分析与设计

###ANTLR生成代码的概览

ANTLR会从`g4`文件生成Parser、Listener、Visitor(如果加上`-visitor`选项)的相关代码。

Parser相关代码提供了用于生成parse tree的函数(以规则命名，返回类型为`SomeRuleContext`)，同时定义了每个规则所对应的`SomeRuleContext`类，该上下文类作为生成的Parse tree的子节点，提供了访问该rule的子rule的相关member functions(以子rule的名称为标识符)。(eg: `decl()` is in class `CompilationUnitContext`)

另外，为方便为visitor提供接口，每个上下文类均提供了相同名字的member function:`accept(... visitor)`。`accept`方法先判断传参是否为`C1ParserVisitor*`，若为是，则调用该上下文类的visit方法。

另外，为方便为listener提供接口，每个上下文类均提供了相同名字的member function:`enterRule()`, `exitRule()`。

Visitor相关代码包含`C1ParserBaseVisitor`类，`C1ParserBaseVisitor`类提供了各个规则的`visitSomeRule`方法，其默认实现为返回访问当前节点所有子节点的结果`visitChildren()`。本实验的`syntax_tree_builder`类继承了此类，`visitSomeRule`方法由我们自己编写。

当我们得到`ParseTree`对象时，有两种分析`ParseTree`的方式：

- use a listener

  ParseTreeWalker的`walk()`函数将会逐一访问子节点，并在每次进入rule之前先执行该Rule的`enterRule`，每次退出rule后执行该rule的`exitRule`。

- use a visitor

  此方式可自己定制访问路线。通过编写`visitSomeRule()`函数，从传入的Context\*类型中得到想要深入访问的子节点，再次调用`visit`。

  实验框架代码调用最顶层的`visit(*ctx)`。由属于ANTLR C++库的`AbstractParseTreeVisitor`类提供最顶层的`visit(Parsetree *tree)`方法(在本Lab中，传入的tree就是`CompilationUnitContext`)。该方法会调用tree的`accept`。如前一段所述，`accept`再调用rule的`visitSomeRule`方法。我们的代码得以执行。

### 设计

本次实验的工作集中在编写各个`visitSomeRule()`函数。

每个`visitSomeRule()`的工作流程类似：分析传入的\*ctx，判断属于该rule的哪个选择，再新建相应的语法节点(syntax tree node)。主要困难有三：

- 每条rule，与每个语法节点并不是一一对应的关系，以下情况均有出现：

  - 一条rule的多个选择，甚至是多条rule的某些选择，均对应一种类型的语法节点，只是语法节点的字段不同

    如：`constdef: Identifier Assign exp`和`vardef: Identifier Assign exp`均对应`var_def_stmt_syntax`类型的语法节点，只是语法节点内的`isconst`字段有区别。

  - 一条rule会对应到多个语法节点。比如`stmt`在文法里均表示“语句”这一类型，但在语法数据结构里，“赋值语句”，“声明语句”

  故写代码时需要先理清当前rule可能会映射到哪几个类型的语法节点，再写判断逻辑。

- 写程序时需要用到ANTLR提供的API函数。但ANTLR并没有提供详细的C++平台的API文档。比较靠谱的办法只有深入源码查看`ParseTree`类的定义(倒是可以看Java平台的文档，比较类似，但是还是有很多细节没有说明)。

  例如，一个节点的所有子节点构成的vector，可通过访问`children`成员来得到。

  又例如：为了能分别出不含数组长度声明的数组定义，我需要判断在`[`之后的符号是否为`exp`类型。于是需要实现在遍历子节点过程中，判断当前节点是否是终结符`[`(而不是判断是不是某个非终结符，非终结符的类型是`...Context`)，就不能用库函数`antlr::is<typename T>(*node)`来判断。因为所有终结符都是`TerminalNode*`这个类型，无法用`antlr::is`区分开。这时就先需要用`TerminalNode`类的成员`getSymbol()`来得到`Token*`类型的符号，再调用`getType()`来得到为每个终结符分配的枚举类型，即一个整数。而`getType()`返回的到底是什么，只能通过看源码来确认。

  (Java文档对`getType()`的解释是："Get the token type of the token"，**但是我仅凭此无法确认token type就是指的是为每个终结符分配的整数值**)

- 程序中大量用到了智能指针，template，以及通用的类型`antlr4::Any`。有些杂项需要注意，否则编译会出错：

  存储成`Any`类型的对象，再用`as`转换成原对象时，`as`的参数不能是原类型以外的类型(即使是原类型的子类或父类)。

  在一个可能产生多种类型的语法节点的`visitSomeRule`函数中(如`visitStmt`)，最终返回值应用`static_cast`转换成父类，这样在上层调用`as`时就不用考虑多种情况。

  ​



## troubleshooting记录

许多错误都来源于**设计**中提到的各种注意事项。其他的以下错误如下：

- 出现`std::badcast`异常

  原因是使用`as`时，存储时的类型与取出时指定的类型不匹配。


- 部分`visit(*ctx)`的参数类型错误(提示不存在这种类型的`visit`)

  原因如下：

  出错的代码类似为：`visit(ctx->exp()[0])`

  当某个上下文类SomeContext内的某个选择可能有多个exp节点时，调用`exp()`的返回结果就是一个vector，vector元素为每个exp元素的指针，但如果可以确定SomeContext内的所有选择最多也只有一个exp节点时，`exp()`的返回结果就是指向该exp节点的指针。

  出错代码中ctx内部最多只有一个exp，故`ctx->exp()`已经是想要的结果了，自己之前还是以为它是向量，于是加上了`[0]`。

## 重点与难点 解答

1. 了解、使用ANTLR分析树的编程接口，书面总结它们与你在lab1-2中写的文法之间的关系

   已在**分析与设计**的**ANTLR生成代码的概览**中总结。

2. 学习使用 Vistor 访问者模式来构建AST

   这个不是问题吧... :blush:

3. ATN的英文全称是什么，它代表什么

   Augmented transition network. 这是从RTN(Recursive Transition Network)发展而来的。而RTN是由状态转换图发展而来的。它们间的区别如下：

   - 状态转换图中，每个节点间的转换边均代表着终结符。

   - RTN中引入了递归机制，转换边可以代表非终结符。该非终结符又对应着一个新的RTN。当遇到有非终结符的转换边时，将当前状态压栈，跳转到另一RTN尝试继续匹配。

   - ATN在RTN中加入了可由当前状态进行更改的寄存器。而每次状态跳转可由这些寄存器的值和当前输入符号决定。ATN有和图灵机一样的计算能力。

4. SLL的英文全称是什么

   上下文无关文法，满足：

   - 没有空的右节点
   - 每个非终结符的每个选择都以不同的终结符开始(LL文法的特征)
   - 没有左递归(LL文法的特征)

   可认为是没有空的右节点的LL文法。

   | Grammar   | 文法两义                       | 试探回朔   |
   | --------- | -------------------------- | ------ |
   | SLL       | 无两义                        | 无回朔    |
   | LL        | 无两义                        | 无回朔    |
   | ANTLR LL* | 规定规则中的第一条最优先。以及用语义推测来解决二义性 | 可能存在回朔 |

5. 了解并总结enterRecursionRule、unrollRecursionContexts、adaptivePredict函数的作用、接口和主要处理流程。

   `enterRecursionRule`在ANTLR C++ Library中定义并实现。该函数和`enterRule`都用来构造`ParseRuleContext`。

   `parse`为暴露给用户的接口。`parse`函数内若判断出开始解析的rule是左递归的，则调用`enterRecursionRule`。与`enterRule`相比，`enterRecursionRule`多传入了要进入的规则的优先级，并将优先级压栈。

   Parser类中的`_ctx`和`state`，记录当前分析的状态和上下文，对member functions均可见，在每次`enterRecursionRule`执行时都会被改变。

   `parse`函数在调用`enterRecursionRule`或`enterRule`后进入循环，反复调用`unrollRecursionContexts`。

   `adaptivePredict`根据传入的`*ctx`，输入符号，和当前处在的决定(decision)来决定下一个转换是哪一个。

   `unrollRecursionContexts`用于从左递归上下文中弹出，将当前状态设为其父上下文对应的状态。

6. 错误处理机制

   处理错误包括处理errors和warnings。

   默认错误恢复逻辑可以处理单 token 的冗余和缺失，在失配时自动扫描至下一处可以开始匹配的位置。

   处理warnings，总的思想是在构建ParseTree及之前的步骤中，承认该warning是合法的.


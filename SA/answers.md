# Answers

> PB15000102 王嵩超

## 3-1

遇到问题：当`test.c`中包含标准库中的函数时，`clang -cc1 -ast-view test.c`这条命令找不到相应的头文件。

解决办法：将-cc1去掉并加上-v，在输出中得到include path，再将命令改为：

```bash
clang -cc1 -analyze -ast-view test.c -I/usr/local/include -I/media/songchaow/DATA/llvm/build/bin/../lib/clang/4.0.1/include -I/usr/include/x86_64-linux-gnu -I/usr/include
```

### `test.c`、`AST.svg`、`CFG.svg`和`ExplodedGraph.svg`之间的联系与区别

`AST.svg`展示的是抽象程序树。这是在词法分析与语法分析阶段完成的，可以通过对`test.c`进行分析来完成。

`CFG.svg`展示的是控制流图。这是在语义分析阶段完成的，可以通过遍历AST来生成。

`ExplodedGraph.svg`展示了analyzer每一步的分析过程，analyzer可以认为是在控制流图上执行的分析过程。在`test.c`这种有循环的程序中，循环被静态分析了5次(因为i值的取值有5个)。

## 3-2

1. Checker 对于程序的分析主要是在 CFG 上进行。

2. [ExplodedGraph](http://clang.llvm.org/doxygen/classclang_1_1ento_1_1ExplodedGraph.html)内包含的[ExplodedNode](http://clang.llvm.org/doxygen/classclang_1_1ento_1_1ExplodedNode.html)包含的[ProgramState](http://clang.llvm.org/doxygen/classclang_1_1ento_1_1ProgramState.html)。

3. 第一行：

   - 产生两个[SVal](http://clang.llvm.org/doxygen/classclang_1_1ento_1_1SVal.html)，表示3, 4两个整形值
   - 产生两个SVal，表示x, y的左值(`MemRegion`)

   第二行：

   - 产生两个SVal，分别表示指针p的内存地址和表示x的内存地址(`MemRegion`)

   第三行：

   - 产生四个SVal，分别表示指针p的`MemRegion`，整形值`1`的值，指针p加1后的`MemRegion`，指针p加1后的解引用

## 3-3

1. 其实自己在这里总结的也只是皮毛。

   智能指针本身不再是一个指针变量，而是一个对象。作为指针的管理者，智能指针的使用需要通过其类提供的接口来完成。不过通过运算符重载，不少操作已经和传统指针具有相同形式(比如判断布尔值，已经被重载为检测其管理的指针是否为`null`；智能指针的`->`运算符，也被重载为对其指针的解引用与成员的访问)

   智能指针还会自动销毁其指向对象，在某些场合避免内存泄漏。

   智能指针分为`unique_ptr`, `shared_ptr`, `weak_ptr`, `auto_ptr`。它们不同在于对指向对象的管理方案。

   - 当`unique_ptr`指向的对象通过`reset()`改变，或者`unique_ptr`本身被销毁时，原来所指向的对象也被销毁。
   - 当所有指向同一对象的`shared_ptr`均发生下列任一种情况时，原来所指向的对象也被销毁。
     - 指向了别的对象
     - `shared_ptr`被销毁
   - `weak_ptr`用来指向一个`shared_ptr`所指向的对象n，但当该`shared_ptr`被销毁时，即使`weak_ptr`没被销毁，该对象也被销毁了。
   - `auto_ptr`维护用`new`表达式创建的对象，并在指针被销毁时销毁该对象。

2. 为了减少可执行程序和代码的大小。

   在LLVM中统一地用类型`antlrcpp::Any`类型来返回。并用 [*isa<>, cast<>, and dyn_cast<>*](http://releases.llvm.org/3.9.0/docs/ProgrammersManual.html#isa)来判断类型。

3. 希望同时接受 C 风格字符串和 std::string时，可以将参数声明为`StringRef`类型。

4. 匿名空间的作用相当于`C`里面的`static`，虽然`static`在C++内也可用，但匿名空间可以一次性将整个类变为其他文件不可见。

## 3-4

1. checker对类型为file handler的符号保存了在当前节点该符号所对应的handler是`opened`还是`closed`的状态。

   所有该记录的符号的状态保存在`ProgramStateRef state`，`state`是匹配类型，在之前通过宏指明了，该匹配类型是从`SymbolRef`到`StreamState`的匹配。

   `StreamState`是单个符号的状态类型。

2. 3. ​

   状态在程序中出现`fopen`和`fclose`的调用时(直接改变该符号对应handler的状态)、结束一个语句块时(检查是否有未关闭的handler，而符号即将脱离生存期)、当符号所代表的指针“逃离”时(分析器不知道指针之后会指向哪里，故以后不再对此符号分析，以防在以后出现错误判断。)



4. 这个函数处理的是当指向file handler的指针“逃离”时的情况。

   首先，导致指针逃离可能有多种原因。

   其中一种是调用函数时将指针作为函数参数，该函数可能对指针指向的handler进行了操作，从而使我们不知道调用后handler的状态。但是如果能够判断出该函数不可能存在关闭handler的行为，则该函数调用对该指针指向的handler的分析无影响。

   故`checkPointerEscape`首先检查含有该指针的被调函数能不能保证不存在关闭handler的行为，如果是，则`checkPointerEscape`不做任何事情。

   否则`checkPointerEscape`会不再分析这些逃离的指针。

5. 能够识别同一条控制流路径中两次连续的`fclose`，以及绝大部分调用了`fopen`但没有调用`fclose`的handler。

   局限性：对于在某个子函数内可能会关闭该文件、也可能不会关闭该文件的情形，该checker不会检测出来，而是直接忽略。如下的C程序可以体现该局限性，因为`fprint`被判断为可能会关闭该文件，从而`fout`不再被考虑。

   ```c
   void fprint(ofstream &fout,int i)
   {
       fout << "haha";
     	if(i==0)
       	fout.close();
   }
   int main()
   {
       ofstream fout("test.c");
     	for(int i=5;i>0;i--)
       	fprint(fout,i);
   }
   ```

   ​

## 3-5

1. 如下文件需要增加或修改：

   - Checker的实现代码`***.cpp`
   - `include/clang/StaticAnalyzer/Checkers/Checkers.td`被修改，需要增加该checker的定义
   - `lib/StaticAnalyzer/Checkers/CMakeLists.txt`需要被修改，以让`CMake`知道该Checker

2. `clang_tablegen`用来以特定的方式调用`tablegen`。

   其定义在此，通过在调用tablegen前设好环境变量。

   ```cmake
   function(clang_tablegen)
     # Syntax:
     # clang_tablegen output-file [tablegen-arg ...] SOURCE source-file
     # [[TARGET cmake-target-name] [DEPENDS extra-dependency ...]]
     #
     # Generates a custom command for invoking tblgen as
     #
     # tblgen source-file -o=output-file tablegen-arg ...
     #
     # and, if cmake-target-name is provided, creates a custom target for
     # executing the custom command depending on output-file. It is
     # possible to list more files to depend after DEPENDS.

     cmake_parse_arguments(CTG "" "SOURCE;TARGET" "" ${ARGN})

     if( NOT CTG_SOURCE )
       message(FATAL_ERROR "SOURCE source-file required by clang_tablegen")
     endif()

     set( LLVM_TARGET_DEFINITIONS ${CTG_SOURCE} )
     tablegen(CLANG ${CTG_UNPARSED_ARGUMENTS})

     if(CTG_TARGET)
       add_public_tablegen_target(${CTG_TARGET})
       set_target_properties( ${CTG_TARGET} PROPERTIES FOLDER "Clang tablegenning")
       set_property(GLOBAL APPEND PROPERTY CLANG_TABLEGEN_TARGETS ${CTG_TARGET})
     endif()
   endfunction(clang_tablegen)
   ```

   ​

3. `td`文件常用来包含具体领域内的大量定义，如x86体系结构的各寄存器信息。利用llvm的`tblgen`工具通过`td`文件生成C++的include定义。

   这样做可以使外部引用的信息(像Checker这样自己编写的类似插件的东西)易于配置和修改，而不是需要手写头文件。

## 4-1

- 缺陷

  对C++模板分析的能力不够强

  对C++等语言异常处理的支持

  对C++`new`与`delete`的分析有待加强

  等等

- 这里以动态内存分配缺陷检查为例。使用`unix.Malloc`Checker。

  该checker能够检查出一部分在顺序执行中出现的连续`free()`和`malloc()`

  测试发现，当程序存在循环中动态分配内存时，该checker无法检测到。例如：

  ```c
  #include <stdlib.h>
  int function()
  {
      int a = 5;
      int *p;
      for(;a>0;a--)
          p = malloc(sizeof(int));
      return 0;
  }
  ```

  该Checker的源码位于`tools/clang/lib/StaticAnalyzer/Checkers/MallocChecker.cpp`中。

  该Checker类中的`RefState`用来指明每个引用指针目前的状态(包括已分配存储空间，已释放存储空间，已“逃离”等)

  一共有10个事件将会触发检查函数：`DeadSymbols`, `PointerEscape`, `ConstPointerEscape`, `PreStmt<ReturnStmt>`, `PreCall`, ...，每个检查函数将会更新各RefState。
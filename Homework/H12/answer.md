# HW12
>   PB15000102 王嵩超

## 测试程序的编译说明
运行本目录下的`Makefile`即可完成编译。

可执行文件会生成在本目录。后缀`_gcc`和`_clang`表示是由`gcc`还是`clang`生成的。

汇编码会生成在assembly文件夹。

>   编译中出现警告，是因为`printf`函数未显式声明。

## 8-5
可用Visual Studio Code编辑器比较`test8-5-no-abs_clang.asm`和`test8-5_clang.asm`两个汇编文件。可发现仅在`.LBB0_2`段内有不同。

**test8-5-no-abs**

保存rbp寄存器后，`fact`先取出静态变量i的值至寄存器%eax，减去一，再保存到i。将%eax加一，存入以-8(%rbp)开始的4个字节。

再次调用`fact`，将保存在%eax的返回结果与i+1(位于-8(%rbp))相乘，再保存在%eax中，作为返回值。


**test8-5**

保存rbp寄存器后，`fact`先取出静态变量i的值至寄存器%eax，减去一，再保存到i。直接将%eax存入以-8(%rbp)开始的4个字节。

将edi置1作为传参，调用`abs`，将存于%eax的返回结果(1)与-8(%rbp)相加，结果存于-12(%rbp)，再次调用`fact`，将结果%eax与-12(%rbp)相乘，存于-4(%rbp)，并取至%eax返回。

**运行结果**

两个程序的输出结果均为`120`.

## 补充题
可用Visual Studio Code编辑器比较`test-supple_clang.asm`和`test-supple-global-i_clang.asm`两个汇编文件。可发现两个文件的结构完全相同，只是在对变量`i`的引用方式上有区别。前者是对局部变量的引用，通过%rbp加上偏移量寻址；后者是直接对全局变量寻址。

**运行结果**

gcc所编译的可执行文件输出为`6\n6`,clang所编译的可执行文件输出为`7\n9`。

对它们生成的汇编码进行分析发现，`clang`对于多个自增表达式的加法运算，会先将右表达式依次自增，用每次刚自增后的值作为操作数进行加法运算；

故`clang`的操作数总为1,2,3。只是它们出现的顺序在两次计算中可能不一样，结果均为6。

而`gcc`会先进行完自增操作，用所有自增操作之后的结果作为操作数进行加法运算。

第一次计算中，两操作数为i++和i++。进行两次自增后再相加，得到4。再计算4+(i++)，即得到7；第二次计算中，由于括号改变了优先级，两操作数为`i++`和`(i++)+(i++)`，故在加法之前，i就自增成了3，故最后得到9。
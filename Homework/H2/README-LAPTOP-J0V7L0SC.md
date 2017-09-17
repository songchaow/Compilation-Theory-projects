# Homework 02

> PB15000102 王嵩超

> **注：**
>
> 作业原要求为：手工编写能识别输入串中多个满足该NFA的记号的词法分析程序。

> 要求未明确指出，多个记号是由空格分隔还是怎样。
>
> 我目前把要求理解并实现为：
>
> ​        找出输入字符串中所有匹配给定正则表达式的子串，功能类似python的`re.search()`。
>
> ​        匹配的子串尽可能达到最大长度。

9.10 更新：

​    根据QQ公告修改：

- 会尽量匹配最长的正规式。
- 程序匹配某个正规式后，会再该式之后继续查找，而不是在下一字符查找。
- 程序会parse出所有的词法单元(即被匹配的字符串中，对应的aa\*和bb\*两部分)。
- **程序具有一定的容错能力**：在aa\*前、aa\*与bb\*之间、bb\*出现的非法字符会被忽略。

## Buildings

源程序为`main.c`。

在H2目录下执行：

```
gcc main.c
```

即可完成构建。

## Usage

构建完成后，执行输出程序。输入字符串，则可以输出正则表达式`aa*|bb*`在该字符串中的匹配结果。

输入`aaab`，匹配到如下结果：

```powershell
Input a string:
abbb
Find matching lexical unit: a
Find matching lexical unit: bbb
请按任意键继续. . .
```

容错测试：

```powershell
Input a string:
abbbxxaaaibb
Find matching lexical unit: a
Find matching lexical unit: bbb
Omitting an invalid character...
Omitting an invalid character...
Find matching lexical unit: aaa
Omitting an invalid character...
Find matching lexical unit: bb
请按任意键继续. . .
```


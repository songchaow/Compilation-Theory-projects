# Homework 02

> PB15000102 王嵩超

> **注：**
>
> 作业原要求为：手工编写能识别输入串中多个满足该NFA的记号的词法分析程序。

> 要求未明确写出，多个记号是由空格分隔还是怎样。
>
> 我目前把要求理解并实现为：
>
> ​        找出输入字符串中所有匹配给定正则表达式的子串，功能类似python的`re.search()`。
>
> ​        匹配的子串尽可能达到最大长度。

## Buildings

源程序为`main.c`。

在H2目录下执行：

```
gcc main.c
```

即可完成构建。

## Usage

构建完成后，执行输出程序。输入字符串，则可以输出正则表达式`aa*|bb*`的匹配结果。

输入`aaab`，匹配到如下结果：

```
Input a string:
aaab
match the re at position 0, with length 3:aaa
match the re at position 1, with length 2:aa
match the re at position 2, with length 1:a
match the re at position 3, with length 1:b
请按任意键继续. . .
```


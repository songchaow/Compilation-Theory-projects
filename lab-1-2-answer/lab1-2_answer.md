# 关于左递归

## 调用左递归问题相关文法的测试程序说明

该测试程序是一个python脚本，通过调用同目录下由`antlr`生成的`...Lexer.py`, `...Listener.py`, `...Parser.py`这三个parser脚本，完成测试工作。

具体的测试工作为：让用户输入一个符合该文法(即一个表达式)的字符串，调用parser计算出该表达式的值。

## 重点和难点 回答

### `ANTLR`支持的左递归类型

`ANTLR 4`接受任何不包含间接左递归和隐藏左递归的上下文无关文法。



### `ANTLR`对支持的左递归的处理

对于支持的左递归，会按优先级递减的顺序从第一个可用选择来试探。所以被`|`分隔的第一个选择应是优先级最高的运算。

加规则在乘规则的前一行：

示例位于`grammar/AddFirst.g4`

![addfirst](add_first.png)

乘规则在加规则的后一行：

示例位于`grammar/MultFirst.g4`

![multfirst](mult_first.png)

事实上，处理后的规则为：

```
expr[int pr] : id
			( {4 >= $pr}? '*' expr[5])
			| {3 >= $pr}? '+' expr[4])
			| {2 >= $pr}? '(' expr[0])
```

如果前面的{... >= $pr}条件不成立，则该条选择不会被考虑。这样就避免了二义性。

### 不支持的左递归示例

两种不支持的左递归的示例位于`grammar/UnsupportedLeftRecursive.g4`

间接和隐式左递归均涉及到对多个表达式。如果要全部去除左递归，会导致指数级量级的转换过的语法。故未被采用。

参见：[report](antlr.org/papers/allstar-techreport.pdf)


# 第3章 处理数据

## 3.1 简单变量

程序存储信息的3个基本属性：
* 信息存储在哪里
* 存储什么值
* 存储什么类型的信息

举例：
```
int braincount;
braincount = 5;
```
上述语句告诉程序，它正在存储整数，并使用名称braincount来表示该整数的值（5）。

实际上，程序先找到一块可以存储整数的内存，将该内存单元标记为braincount，并将5复制到该内存单元中；可以用braincount来访问该内存单元，也可以使用`&运算符来检索braincount的内存地址`。

### 3.1.1 变量名
C++ 命名规则如下：
* 名称只能包含字母、数字、下划线
* 名称第一个字符不能是数字
* 字母区分大小写
* 不能将C++关键字作为名称
* 以两个下划线及大写字母打头的名称保留给实现使用，以一个下划线开头的名称保留用作全局标识符
* C++名称没有长度限制

#### 3.1.2 整形
使用的内存越大，则可以存储的整数值范围越大。C++存储数据的宽度（使用内存越多，宽度越大）递增排序如下：
* char
* short
* int
* long
* long long(C++11新增)
上述类型都有**有符号和无符号**版本，所以有10种类型可选。

#### 3.1.3 整形short、int、long和long long
# 第3章 处理数据
OOP(面向对象编程)本质是设计并扩展自己的数据类型。要创建自己的数据类型，首先要了解C++的内置类型。

C++ 内置类型分为两组：
* 基本类型， 整数和浮点数
* 复合类型， 包含数组、字符串、指针和结构

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

### 3.1.2 整型
使用的内存越大，则可以存储的整数值范围越大。C++存储数据的宽度（使用内存越多，宽度越大）递增排序如下：
* char
* short
* int
* long
* long long(C++11新增)
上述类型都有**有符号和无符号**版本，所以有10种类型可选。

### 3.1.3 整型short、int、long和long long

- short至少16位；
- int至少与short一样长；
- long至少32位，且至少与int一样长；
- long long至少64位，且至少与long一样长。


**位和字节**

计算机内存的基本单元是`位（也称比特，bit）`,用二进制的0或1来表示，0或1就代表一位。8位的内存可以有2X2X2X2X2X2X2X2=256种组合，可以表示0-255或者-128到127。

`字节(byte)`通常是指8位的内存单元， 1KB=1024byte, 1MB=1024KB.

**运算符sizeof和头文件limits**

sizeof运算符返回类型或变量的长度，单位为字节。
对类型名（如int）使用sizeof 时，int需要放在括号里，但对于变量名（n_short）使用sizeof时，可用可不用括号。

头文件climits定义了符号常量。
```
// limits.cpp
#include<iostream>
#include<climits>

int main()
{
    using namespace std;
    char n_char = CHAR_MAX;
    short n_short = SHRT_MAX;
    int n_int = INT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    // sizeof operator yields size of type or of variable
    cout << "char is " << sizeof(char) << " bytes." << endl;
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "int is " << sizeof(int) << " bytes." << endl;
    cout << "long is " << sizeof n_long << " bytes." << endl;
    cout << "long long is " << sizeof n_llong << " bytes." << endl;
    cout << endl;

    cout << "Maximum values:" << endl;
    cout << "char: " << n_char << endl;
    cout << "char: " << CHAR_MAX << endl;
    cout << "short: " << n_short << endl;
    cout << "int: " << n_int << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl;
    cout << endl;

    return 0;
}

结果：
char is 1 bytes.
short is 2 bytes.
int is 4 bytes.
long is 8 bytes.
long long is 8 bytes.

Maximum values:
char:
char: 127
short: 32767
int: 2147483647
long: 9223372036854775807
long long: 9223372036854775807
```

issue: 为啥char打印不出来127的值？不可见字符（控制字符）：ASCII有128个字符，其中ASCII值从0~31和127为不可见字符（控制字符）

`字符输出不是整数，而是该整数所代表的ASCII码字符，所以第一个打印是不可见的127 ASCII码。 第二个是有头文件定义了#define CHAR_MAX 127，所以编译的时候CHAR_MAX 直接替换成127。`

表3.1climits中的符号常量

|符 号 常 量|表 示|
|-|-|
CHAR_BIT| char的位数
CHAR_MAX| char的最大值
CHAR_MIN| char的最小值
SCHAR_MAX| signed char的最大值
SCHAR_MIN| signed char的最小值
UCHAR_MAX| unsigned char的最大值
SHRT_MAX| short的最大值
SHRT_MIN| short的最小值
USHRT_MAX| unsigned short的最大值
INT_MAX| int的最大值
INT_MIN| int的最小值
UNIT_MAX| unsigned int的最大值
LONG_MAX| long的最大值
LONG_MIN| long的最小值
ULONG_MAX| unsigned long的最大值
LLONG_MAX| long long的最大值
LLONG_MIN| long long的最小值
ULLONG_MAX| unsigned long long的最大值

> 符号常量-预处理器方式
在climits文件中包含下列类似的语句：

**#define INT_MAX 32767**
C++编译过程中，首先将源码传递给预处理器。该编译指令告诉预处理器，在程序中查找所有的INT_MAX， 并将所有的INT_MAX都替换成32767。

**初始化**

初始化将赋值和声明合并在一起, 如下语句，声明了变量n_int, 并将int的最大值赋值给它。

int n_int = INT_MAX;


### 3.1.4 无符号类型
无符号类型可以增大存储的最大值，当然要知道只有数值不为负数时才能使用无符号类型。

```
// exceed.cpp -- exceeding some integer limits
#include <iostream>
#include <climits>
#define ZERO 0

int main()
{
    using namespace std;
    short short_max = SHRT_MAX;
    short short_min = SHRT_MIN;
    cout << "short_max: " << short_max << endl;
    cout << "short_min: " << short_min << endl;

    short_max = short_max + 1;
    short_min = short_min + 1;

    cout << "short_max plus one: " << short_max << endl;
    cout << "short_min plus one: " << short_min << endl;

    unsigned short unsigned_short_max = USHRT_MAX;
    unsigned short unsigned_short_min = ZERO;
    cout << "unsigned_short_max: " << unsigned_short_max << endl;
    cout << "unsigned_short_min: " << unsigned_short_min << endl;

    unsigned_short_max = unsigned_short_max - 1;
    unsigned_short_min = unsigned_short_min - 1;

    cout << "short_max minus one: " << unsigned_short_max << endl;
    cout << "short_min minus one: " << unsigned_short_min << endl;
    return 0;
}

结果：
short_max: 32767
short_min: -32768
short_max plus one: -32768
short_min plus one: -32767
unsigned_short_max: 65535
unsigned_short_min: 0
short_max minus one: 65534
short_min minus one: 65535
```
short 类型最大值是32767， 加上1后变成了-32768.
unsigned shot类型最小值是0， 减去1后，变成了65535.
这就是典型的`整型溢出行为`，超越了限制，其值将为范围另一端的取值。

![典型的整型溢出行为](./picture/p3_1.png)


### 3.1.5 选择整型类型

* int， 计算机最自然的长度，如果值不为负值，可使用无符号类型
* long, 变量值可能大于16位的整数
* long long, 数值超过20亿
* short, 大型整型数组，可以节省内存
* char, 存储一个字节

### 3.1.6 整型字面值

C++ 中有3种方式来书写整型数值。
* 基数为10，第一位为1-9，例如93
* 基数为8，第一位为0， 第二位为1-7，例如042
* 基数为16， 第一位为0x或者0X，例如0x42

**默认情况下，cout以十进制格式显示整数**，而不管这些整数在程序中是如何书写. 但是cout提供了控制符`dec、hex和oct`，分别用于指示cout以十进制、十六进制和八进制格式显示整数.

```
#include<iostream>

int main()
{
    using namespace std;
    int decimal_int = 42;
    int hexadecimal_int = 0x42;
    int octal_int = 042;

    cout << "decimal_int 42 is (dec)" << decimal_int << endl;
    cout << "hexadecimal_int 0x42 is (dec)" << hexadecimal_int << endl;
    cout << "octal_int 042 is (dec)" << octal_int << endl;

    cout << endl;
    cout << "decimal_int 42 is (dec)" << decimal_int << endl;
    cout << hex;
    cout << "hexadecimal_int 0x42 is (hex)" << hexadecimal_int << endl;
    cout << oct;
    cout << "octal_int 042 is (oct)" << octal_int << endl;
    return 0;
}

结果
decimal_int 42 is (dec)42
hexadecimal_int 0x42 is (dec)66
octal_int 042 is (dec)34

decimal_int 42 is (dec)42
hexadecimal_int 0x42 is (hex)42
octal_int 042 is (oct)42
```

### 3.1.7 C++如何确定常量类型
C++将整型常量存储为int类型， 除非用了特殊后缀。
后缀是放在数字常量后面的字母， 用于表示类型。

* l/L 表示long, 如：2022L
* u/U 表示unsigned int， 如2022U
* ul 表示unsigned long， 如2022UL
* ll 表示long long
* ull 表示unsigned long long

### 3.1.8 char类型


### 3.1.9 bool类型
C++将非零值解释为true，将零解释为false。然而，现在可以使用bool类型来表示真和假了。

```
#include<iostream>

int main()
{
    using namespace std;
    int ans = true;
    int promise = false;
    cout << "ans is " << ans << endl;
    cout << "promise is " << promise <<endl;

    bool start = -100;
    bool stop = 0;
    cout << "start is " << start << endl;
    cout << "stop is " << stop <<endl;
    return 0;
}
结果
ans is 1
promise is 0
start is 1
stop is 0
```

## 3.2 const限定符
关键字`const`叫做限定符，因为它限定了声明的含义。
> const int MONTHS = 12;

MONTHS被初始化后，其值就被固定了，编译器不允许将修改该常量的值，否则报错给只读变量赋值。

```
#include <iostream>

int main()
{
    using namespace std;
    const int MONTHS = 12;
    cout << "MONTHS is " << MONTHS << endl;
    MONTHS = 11;
    return 0;
}

编译结果
constuse.cpp: In function ‘int main()’:
constuse.cpp:8:12: error: assignment of read-only variable ‘MONTHS’
     MONTHS = 11;
            ^
```
使用const的优点：
* 能指定类型
* 可以限定在特定的函数和位置
* 可以将const用于更复杂的类型

## 3.3 浮点数
浮点数可以表示带小数的数字

### 3.3.1 书写浮点数

* 常用写法， 例如0.1， 8.0
* E的写法， 例如2.5e+8, -18.32E4

`E的写法`，指数可以是负也可是是正（负数时除以10的乘方，正数是乘），但是数字中不能有空格， 可以表示非常大的数字，也可以表示非常小的数字。

> d.dddE+n指的是将小数点向右移n位，而d.dddE～n指的是将小数点向左移n位。之所以称为“浮点”，就是因为小数点可移动。

### 3.3.2 浮点类型
C++也有3种浮点类型：float、double和long double。


### 3.3.3 浮点常量
C++也有3种浮点常量：float、double和long double。

* float 类型， 使用`f/F后缀`， 例如：1.234f、2.45E20F
* double 类型， 默认无后缀，例如：8.24、2.4E8
* long double 类型， 使用`l/L后缀`， 例如：2.2L

### 3.3.3 浮点数的优缺点
优点：
* 可以表示整数之间的值
* 有缩放因子，可以表示极大或极小的值

缺点：
* 浮点运算速度通常比整数慢，且精度降低

```
#include <iostream>

int main()
{
    using namespace std;
    float a = 2.34E+22f;
    float b = a + 1.0f;

    cout << "a = " << a << endl;
    cout << "b - a = " << b - a << endl;
    return 0;
}

结果
a = 2.34e+22
b - a = 0
```
2.34E+22是一个小数点左边有23位的数字。加上1，就是在第23位加1。但`float类型只能表示数字中的前6位或前7位`，因此修
改第23位对这个值不会有任何影响。

## 3.4 C++算数运算符
C++有5种基本的算数计算：

* 加（+）
* 减（-）
* 乘（*）
* 除（/）
* 求模（%）

```
#include <iostream>

int main()
{
    using namespace std;
    float hats, heads;

    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Enter a number: ";
    cin >> hats;
    cout << "Enter another number: ";
    cin >> heads;

    cout << "hats = " << hats << "; heads = " << heads << endl;
    cout << "hats + heads = " << hats + heads << endl;
    cout << "hats - heads = " << hats - heads << endl;
    cout << "hats * heads = " << hats * heads << endl;
    cout << "hats / heads = " << hats / heads << endl;
    return 0;
}

结果
Enter a number: 50.25
Enter another number: 11.17
hats = 50.250000; heads = 11.170000
hats + heads = 61.419998
hats - heads = 39.080002
hats * heads = 561.292480
hats / heads = 4.498657
```
11.17加上50.25应等于61.42，但是输出中却是61.419998。这不是运算问题；而是由于float类型表示有效位数的能力有限。记住，**对于float，C++只保证6位有效位**。如果将61.419998四舍五入成6位，将得到61.4200，这是保证精度下的正确值。如果需要更高的精度，请使用double或long double。

### 3.4.1 运算符优先级和结合性
算术运算符遵循的优先级，先乘除，后加减。也可以使用括号来执行自
己定义的优先级。

> float logs = 120 / 4 * 5    // 150 ? 6

当两个运算符作用于同一个操作数，且两个运算符的优先级相同时，C++将看操作数的结合性（associativity）是从左到右，还是从右到左来计算。

乘除都是从左到右结合的，结果是150。

### 3.4.2 除法分支


### 3.4.3 求模运算符

### 3.4.4 类型转换

### 3.4.5 C++11中的auto声明
auto是一个C语言关键字，让编译器能够根据初始值的类型推断变量的类型。
```
auto n = 100;     // n is int
auto x = 1.5;     // x is double
auto y = 1.3e12L  // y is long double
```
# 目录

* [4 复合类型](#复合类型)
    * [4.1 数组](#数组)
        * [4.1.1 程序说明](#程序说明)
        * [4.1.2 数组的初始化规则](#数组的初始化规则)
        * [4.1.3 C++11数组初始化方法](#C++11数组初始化方法)
    * [4.2 字符串](#字符串)
        * [4.2.1 拼接字符串常量](#拼接字符串常量)
        * [4.2.2 在数组中使用字符串](#在数组中使用字符串)
        * [4.2.3 字符串输入](#字符串输入)
        * [4.2.4 每次读取一行字符串输入](#每次读取一行字符串输入)
        * [4.2.5 混合输入字符串和数字](#混合输入字符串和数字)


# 4 复合类型
* 创建和使用数组。
* 创建和使用C-风格字符串。
* 创建和使用string类字符串。
* 使用方法getline( )和get( )读取字符串。
* 混合输入字符串和数字。
* 创建和使用结构。
* 创建和使用共用体。
* 创建和使用枚举。
* 创建和使用指针。
* 使用new和delete管理动态内存。
* 创建动态数组。
* 创建动态结构。
* 自动存储、静态存储和动态存储。
* vector和array类简介。
---
## 4.1 数组
数组（array）是一种数据格式，能够存储`多个同类型的值`。
声明数组三要素：
* 存储在每个元素中的值的类型；
* 数组名；
* 数组中的元素数。

> short months[12];//声明创建一个months数组，共有12个元素，每个元素都是short类型的变量。

可以通过`下标或索引来单独访问数组元素`，下标规定从0开始。
**编译器不会检查使用的下标是否有效**，比如months[101]，编译也不会报错。
```
#include <iostream>

int main()
{
    using namespace std;

    // 定义一个大小为 3 的整数数组 yams
    int yams[3];
    yams[0] = 7; // 初始化第一个元素
    yams[1] = 8; // 初始化第二个元素
    yams[2] = 6; // 初始化第三个元素

    // 定义一个大小为 3 的整数数组 yamsconst，并进行初始化
    int yamsconst[3] = {20, 30, 5};

    // 输出 yams 数组元素的总和
    cout << "Total yams = " << yams[0] + yams[1] + yams[2] << endl;

    // 输出 yams[1] 元素对应的成本
    cout << "The package with " << yams[1] << " yams costs "
         << yamsconst[1] << " cents per yam.\n";

    // 计算 yams 数组所有元素对应的成本总和
    int total = yams[0] * yamsconst[0] + yams[1] * yamsconst[1];
    total = total + yams[2] * yamsconst[2];

    // 输出 yams 数组所有元素对应的成本总和
    cout << "The total yam expense is " << total << " cents." << endl;

    // 输出 yams 数组的字节长度和一个元素的字节长度
    cout << "\nSize of yams array = " << sizeof(yams)
         << " bytes.\n";
    cout << "Size of one element = " << sizeof(yams[0])
         << " bytes.\n";

    return 0;
}

result:
Total ymas = 21
The package with 8 yams costs 30 cents per yam.
The total yam expense is 410 cents.

Size of yams array = 12 bytes.
Size of one element = 4 bytes.
```
---
### 4.1.1 程序说明
C++允许在声明语句中初始化数组元素。

`sizeof运算符`返回类型或数据对象的长度（单位为字节）
* 将sizeof用于**数组名**，得到的将是整个数组的字节数。
* 将sizeof用于**数组元素**，则得到的将是该元素的字节数。

这表明yams是一个数组，而yams[1]只是一个int变量。

---

### 4.1.2 数组的初始化规则
* 只有定义时才能初始化，以后不能用
* 不能将一个数组赋值给另外一个数组
* 可以使用下标给数组中的元素赋值

```
int cards[4] = {1, 2, 3, 4}; // okay
int hand[4];                 // okay
hand[0] = 5;                 // okay
hand[4] = {5, 6, 7, 8};      // not allowed, 数组是一种特殊的数据类型，它在定义时需要为每个元素分配内存空间，所以只有在定义时才能进行初始化。
hand = cards;                // not allowed, 数组名本身表示数组的首地址，是一个指针常量。在赋值时，数组名不能被赋值，因为它已经被定义为一个常量，不能被修改。
```


* 初始化数组时，数组元素数目可以少于数组初始化的值，编译器将把其他元素设置为0。

int cards[4] = {1, 2}; 表示，cards[2]和cards[3]都是0.

* 如果初始化数组方括号内为空，则C++编译器会去计算元素个数。

short things[] = {1, 5, 3, 8}; 编译器会根据初始化列表中的元素个数自动推导数组长度为4。

---

### 4.1.3 C++11数组初始化方法
`C++11数组`初始化方法增加一些功能
* 初始化数组时，可省略等号（=）
* 可不在大括号中包含任何东西，所有元素设置为0
* 初始化禁止窄缩转换

int cards[4] {1, 2, 3, 4};

int cards[10] = {};

* 列表初始化
>int arr[] = {1, 2, 3, 4, 5};

* 使用等号赋值
```
int arr[5];
arr[0] = 1;
arr[1] = 2;
arr[2] = 3;
arr[3] = 4;
arr[4] = 5;
```

---

## 4.2 字符串
字符串是存储在内存的连续字节中的一系列字符。

* C 风格字符串

将字符串存储在char数组中，每个字符都位于自己的数组元素中。

C 风格字符串以`空字符串结尾`，即以'\0'结尾。

```
char dog[3] = {'a', 'b', 'c'}; // 字符数组，但不是string
char cat[3] = {'f', 'e', '\0'}; // 字符数组，是C风格string
```

* 字符串常量，用双引号括起来, 用引号括起的字符串隐式地包括结尾的空字符。

```
char bird[11] = "Mr. Cheeps"; // 11个元素，10个字符加上一个 null 终止符
char fish[] = "Bubbles"; // 6个字符加上一个 null 终止符
```

C++对字符串长度没有限制，在确定存储字符串所需的最短数组时，别忘了将结尾的空字符计算在内。

![将数组初始化为字符串](./picture/p4_2.png)

* char size = 'S';
* char size = "S";

字符串常量（使用**双引号**）不能与字符常量（使用**单引号**）互换。

字符常量'S'是字符串编码的简写表示，是83的一种写法。

"S"表示的是两个字符（字符S和\0）组成的字符串，且表示的是字符串所在的`内存地址`，不能直接赋值给字符类型变量。

---


### 4.2.1 拼接字符串常量

任何两个由`空白（空格、制表符和换行符）`分隔的字符串常量都将自动拼接成一个。

第一个字符串的\0字符会被第二个字符串的第一个字符取代。

```
#include <iostream>

int main()
{
    using namespace std;
    char dog[3] = {'a', 'b', 'c'};
    char cat[3] = {'f', 'e', '\0'};
    cout << "dog is " << dog << endl;
    cout << "cat is " << cat << endl;

    char size = 'S';
    // char newSize = "S"; // invalid conversion from ‘const char*’ to ‘char’
    cout << "size is " << size << endl;
    // cout << "newSize is " << newSize << endl;

    cout << "hello," " world." << endl;
    cout << "hello, world." << endl;
    cout << "hello,"
    " world." << endl;

    return 0;
}

result:
dog is abc
cat is fe
size is S
hello, world.
hello, world.
hello, world.
```

---

### 4.2.2 在数组中使用字符串

字符串存储到数组里面：
* 数组初始化为字符串常量
* 将键盘或者文件输入读入到数组里面

```
#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    const int size = 15;
    char name1[size];
    char name2[size] = "C++owboy";

    cout << "Howdy! I'm " << name2;
    cout << "! What's your name?\n";
    cin >> name1;
    cout << "Well, " << name1 << " , your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << "in an array of " << sizeof(name1) << " bytes.\n";
    cout << "Your initial is " << name1[0] << ".\n";
    name2[3] = '\0';
    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << endl;

    return 0;
}

result:
Howdy! I'm C++owboy! What's your name?
Basicman
Well, Basicman , your name has 8 letters and is stored
in an array of 15 bytes.
Your initial is B.
Here are the first 3 characters of my name: C++
```
* sizeof 计算整个数组的长度，15个字节
* strlen() 计算存储在数组中字符串的长度，计算不包含空字符
* name1 最多可以输入14个字符，因为最后一个字符要用来存储字符串的结束符'\0'。如果输入的字符串超过了 name1 数组的长度，cin >> 仍然可以将该字符串读取到 name1 数组中，但会导致数组越界，可能会破坏其他内存区域的数据或引发其他问题。

![使用\0截短字符串](./picture/p4_3.png)

---

### 4.2.3 字符串输入

```
#include <iostream>

int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin >> name;
    cout << "Enter your favorite dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}

result:
Enter your name:
Alistair Dreeb
Enter your favorite dessert:
I have some delicious Dreeb for you, Alistair.
```

上述脚本会有2个问题：
* cin 在遇到`空格、制表符或换行符`时会停止读取，而将剩余部分留在输入流中等待下一次读取。
* cin 在读入字符串时，不会检查数组长度是否足够。如果读入的字符串长度超过数组长度，就会发生数组越界，导致程序崩溃或未定义行为

结果解析：
* cin使用空白（空格、制表符和换行符）来确定字符串的结束位置，这意味着cin在获取字符数组输入时只读取一个单词。读取该单词后，cin将该字符串放到数组中，并自动在结尾添加空字符。

* cin把Alistair作为第一个字符串，并将它放到name数组中。这把Dreeb留在输入队列中。当cin在输入队列中搜索用户喜欢的甜点时，它发现了Dreeb，因此cin读取Dreeb，并将它放到dessert数组中。
---
### 4.2.4 每次读取一行字符串输入

面向行而不是面向单词的方法, 下面两个函数都是**读取一行输入，直到到达换行符**。

* getline() 函数读取整行，通过回车键输入的换行符来确定输
入结尾。丢弃换行符，有两个参数，一个数组名，另一个读取字符数

```
#include <iostream>

int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin.getline(name, ArSize);
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert, ArSize);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}

result:
Enter your name:
Dirk Hamm
Enter your favorite dessert:
Rad home
I have some delicious Rad home for you, Dirk Hamm.
```
* getline() 通过换行符来确定行尾，但不保存换行符，相反，在存储字符串时，用空字符来代替换行符。

![getline( )读取并替换换行符](./picture/p4_5.png)

* get() 保留换行符

>cin.get(name, ArSize);
cin.get(dessert, ArSize);  // a problem

第一次调用后，换行符留在输入列队中，因此第二次调用读取这个换行符，从而认为已经到达行尾，没有可读取的内容。

get()有种变体，使用不带任何参数的cin.get()调用来读取下一个字符（即使是换行符）。

```
#include <iostream>

int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin.get(name, ArSize);
    cout << "Enter your favorite dessert:\n";
    cin.get(dessert, ArSize);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}
```

* 空行和其他问题

### 4.2.5 混合输入字符串和数字
```
#include <iostream>

int main()
{
    using namespace std;
    cout << "What year was your house build?\n";
    int year;
    cin >> year;
    cout << "What is its street and address?\n";
    char address[80];
    cin.getline(address, 80);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";
    return 0;
}

result
What year was your house build?
1966
What is its street and address?
Year built: 1966
Address:
Done!
```
## 定义常量

#### 使用#define 预处理定义常量的形式

```sh
#define identifier value
```

实例

```cpp
#include<iostream>
using namespace std;

#define LENGTH 10
#define WIDTH 5
#define NEWLINE '\n'

int main(){
	int area;
	area = LENGTH * WIDTH;
	cout << area;
	cout << NEWLINE;
	return 0;
}
```

#### 使用const 前缀声明指定的常量

```c++
#include<iostream>
using namespace std;

int main(){
    const int LENGTH = 10;
    const int WIDTH = 5;
    const char NEWLINE = '\n';
    int area;
    
    area = LENGTH*WIDTH;
    cout << area ;
    cout << NEWLINE;
    return 0;
}
```

## c++ 中的类型限定符

| 限定符   | 含义                                                         |
| -------- | ------------------------------------------------------------ |
| const    | const 类型的对象在执行期间不能被修改                         |
| volatile | volatile声明的变量,编译器不会优化                            |
| restrict | restrict 修饰的指针是唯一访问它所指的对象的方式.c++17,已弃用 |

## c++存储类

存储类定义c++程序中变量/函数的可见性和生命周期.c++可用的存储类:

- auto
- register
- static
- extern
- mutable
- thread_local(c++11)

c++17开始,auto关键词不再是存储类说明符,且register关键字被弃用

#### register存储类

register用于定义存储在寄存器而不是RAM中的局部变量,最大范围等于寄存器大小,且不能使用'&'运算符

```c++
{
    register int miles;
}
```

#### static存储类

**static** 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。

static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。

```cpp
#include <iostream>
 
// 函数声明 
void func(void);
 
static int count = 10; /* 全局变量 */
 
int main()
{
    while(count--)
    {
       func();
    }
    return 0;
}
// 函数定义
void func( void )
{
    static int i = 5; // 局部静态变量
    i++;
    std::cout << "变量 i 为 " << i ;
    std::cout << " , 变量 count 为 " << count << std::endl;
}
/*output
变量 i 为 6 , 变量 count 为 9
变量 i 为 7 , 变量 count 为 8
变量 i 为 8 , 变量 count 为 7
变量 i 为 9 , 变量 count 为 6
变量 i 为 10 , 变量 count 为 5
变量 i 为 11 , 变量 count 为 4
变量 i 为 12 , 变量 count 为 3
变量 i 为 13 , 变量 count 为 2
变量 i 为 14 , 变量 count 为 1
变量 i 为 15 , 变量 count 为 0
*/
```

#### extern储存类

**extern** 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。当您使用 'extern' 时，对于无法初始化的变量，会把变量名指向一个之前定义过的存储位置。

当您有多个文件且定义了一个可以在其他文件中使用的全局变量或函数时，可以在其他文件中使用 *extern* 来得到已定义的变量或函数的引用。可以这么理解，***extern* 是用来在另一个文件中声明一个全局变量或函数**。

```cpp
//main.cpp
#include <iostream>
int count ;
extern void write_extern();
int main()
{
   count = 5;
   write_extern();
}
//support.cpp
#include <iostream>
extern int count;
void write_extern(void)
{
   std::cout << "Count is " << count << std::endl;
}
//sh
//g++ main.cpp support.cpp -o write
```

#### mutable存储类

mutable 说明符仅适用于类的对象。它允许对象的成员替代常量。也就是说，mutable 成员可以通过 const 成员函数修改。

#### thread_local 存储类

使用 thread_local 说明符声明的变量仅可在它在其上创建的线程上访问。 变量在创建线程时创建，并在销毁线程时销毁。 每个线程都有其自己的变量副本。

thread_local 说明符可以与 static 或 extern 合并。

可以将 thread_local 仅应用于数据声明和定义，thread_local 不能用于函数声明或定义。

## for循环

```c++
int my_array[5] = { 1, 2, 3, 4, 5 };

// 不会改变 my_array 数组中元素的值
// x 将使用 my_array 数组的副本
for (int x : my_array)
{
    x *= 2;
    cout << x << endl;
}

// 会改变 my_array 数组中元素的值
// 符号 & 表示 x 是一个引用变量，将使用 my_array 数组的原始数据
// 引用是已定义的变量的别名
for (int& x : my_array)
{
    x *= 2;
    cout << x << endl;
}

// 还可直接使用初始化列表
for (int x : { 1, 2, 3, 4, 5 })
{
    x *= 2;
    cout << x << endl;
}
```

## switch语法

```cpp
switch(expression){//1.expression 必须是一个整型或枚举或是可以转化为整型或枚举的class
    case constant-expression  ://2.case 的 constant-expression 必须与 switch 中的变量具有相同的数据类型，且必须是一个常量或字面量。
       statement(s);
       break; // 3.可选的,没有break会执行下一个case
    case constant-expression  :
       statement(s);
       break; // 可选的
  
    // 您可以有任意数量的 case 语句
    default : // 4.可选的
       statement(s);
}
```

## 函数

```cpp 
#include <iostream>
using namespace std;
 
// 函数声明
int max(int num1, int num2);
 
int main ()
{
   // 局部变量声明
   int a = 100;
   int b = 200;
   int ret;
 
   // 调用函数来获取最大值
   ret = max(a, b);
 
   cout << "Max value is : " << ret << endl;
 
   return 0;
}
 
// 函数返回两个数中较大的那个数
int max(int num1, int num2) 
{
   // 局部变量声明
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}
```

#### 函数参数

形式参数,在进入函数时被创建,退出时被摧毁.

有三种函数调用传参的方式:

| 调用类型 | 描述                                                         |
| -------- | ------------------------------------------------------------ |
| 传值调用 | 该方法把参数的实际值赋值给函数的形式参数。<br>在这种情况下，修改函数内的形式参数对实际参数没有影响。 |
| 指针调用 | 该方法把参数的地址赋值给形式参数。<br>在函数内，该地址用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。 |
| 引用调用 | 该方法把参数的引用赋值给形式参数。<br>在函数内，该引用用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。 |

#### 参数默认值

调用函数时,如果未传递参数,则会使用默认值.

只能连续的n个右参数,有默认选项.

```cpp
#include <iostream>
using namespace std;
 
int sum(int a, int b=20)
{
  int result;
  result = a + b;
  return (result);
}

int main ()
{
   // 局部变量声明
   int a = 100;
   int b = 200;
   int result;
 
   // 调用函数来添加值
   result = sum(a, b);
   cout << "Total value is :" << result << endl;
 
   // 再次调用函数
   result = sum(a);
   cout << "Total value is :" << result << endl;
 
   return 0;
}
```

#### Lambda函数与表达式

C++11提供类对匿名函数的支持,称谓Lambda函数(也叫Lambda表达式)

Lambda表达式把函数看作对象.

具体形式:

```c++
[capture](parameters)->return-type{body}
```

```cpp
//例如
[](int x,int y){return x<y;}

//如果没用返回值可以表示为:
//[capture](parameters){body}
[]{++global_x;}

//复杂的例子
[](int x,int y)->int{int z=x+y;return z+x;}
```

在Lambda表达式内可以访问当前作用域的变量,这是闭包行为.

c++变量传递有传值和传引用的区别:

```cpp
[]      // 沒有定义任何变量。使用未定义变量会引发错误。
[x, &y] // x以传值方式传入（默认），y以引用方式传入。
[&]     // 任何被使用到的外部变量都隐式地以引用方式加以引用。
[=]     // 任何被使用到的外部变量都隐式地以传值方式加以引用。
[&, x]  // x显式地以传值方式加以引用。其余变量以引用方式加以引用。
[=, &z] // z显式地以引用方式加以引用。其余变量以传值方式加以引用。
```

对于[=]或[&]的形式，lambda 表达式可以直接使用 this 指针。但是，对于[]的形式，如果要使用 this 指针，必须显式传入：

```cpp
[this]() { this->someFunc(); }();
```

#### c++传递数组给函数

```cpp
//方式1
//形参是一个指针
void myFunction(int *param)
//方式2
//形参是一个已定大小的数组
void myFunction(int param[10])
//方式3:
//形参是一个未定大小的数组
void myFunction(int param[])
```

#### c++从函数返回数组

c++不允许返回一个完整的数组作为函数的参数,如果想要返回一个数组,必须声明一个返回指针的函数:

```c++
int *myFunction(){
    
}
```

c++不支持在函数外返回局部变量的地址,除非定义局部变量为static变量.

## c++字符串

#### c风格字符串

```cpp
char site[7]={'R','U','N','O','O','B','\0'};
char site[]="RUNOOB";
```

#### String类

```cpp
#include<string>
using namespace std;
int main(){
    string str1 = "runoob";
}
```

## c++引用

#### c++引用vs指针

- 不存在空引用。引用必须连接到一块合法的内存。
- 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
- 引用必须在创建时被初始化。指针可以在任何时间被初始化。

```cpp
int i = 17;

int& r = i;
```

引用常用于函数参数列表和函数返回值.

| 概念             | 描述                                                     |
| ---------------- | -------------------------------------------------------- |
| 把引用作为参数   | C++支持把应用作为参数传递给函数,这比传递一般的参数更安全 |
| 把引用作为返回值 |                                                          |

**C++ 函数可以返回一个引用，方式与返回一个指针类似。当函数返回一个引用时，则返回一个指向返回值的隐式指针。这样，函数就可以放在赋值语句的左边。**

当返回一个引用时，要注意被引用的对象不能超出作用域。所以返回一个对局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用。

```cpp
int& func() {
   int q;
   //! return q; // 在编译时发生错误
   static int x;
   return x;     // 安全，x 在函数作用域外依然是有效的
}
```

## 基本输入输出

| 头文件       | 函数和描述                                                   |
| ------------ | ------------------------------------------------------------ |
| `<iostream>` | 该文件定义了 cin、cout、cerr 和 clog 对象，分别对应于标准输入流、标准输出流、非缓冲标准错误流和缓冲标准错误流。 |
| `<iomanip>`  | 该文件通过所谓的参数化的流操纵器（比如 setw 和 setprecision），来声明对执行标准化 I/O 有用的服务。 |
| `<fstream>`  | 该文件为用户控制的文件处理声明服务。                         |

#### 标准输出流

预定义的对象 cout 是 iostream 类的一个实例。cout 对象"连接"到标准输出设备，通常是显示屏。

#### 标准输入流

预定义的对象 cin 是 iostream 类的一个实例。cin 对象附属到标准输入设备，通常是键盘。

#### 标准错误流

预定义的对象 cerr 是 iostream 类的一个实例。cerr 对象附属到标准输出设备，通常也是显示屏，但是 **cerr 对象是非缓冲的**，且每个流插入到 cerr 都会立即输出。

#### 标准日志流

预定义的对象 clog 是 iostream 类的一个实例。clog 对象附属到标准输出设备，通常也是显示屏，但是 **clog 对象是缓冲的**。这意味着每个流插入到 clog 都会先存储在缓冲区，直到缓冲填满或者缓冲区刷新时才会输出。
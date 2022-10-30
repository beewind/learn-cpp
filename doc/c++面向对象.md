# c++面向对象

## 类&对象

### 类的定义

```cpp
class classname//关键字 类名
{
    Access specifiers://访问修饰符
    	Date members/variables;//变量
    	Mermber functions(){}//方法
};
```

```cpp
class Box{
    public:
    	double length;
    	double width;
    	double height;
}
```

### 访问数据成员

```cpp
#include <iostream>
using namespace std;

class Box{
    public :
        double length;
        double breadth;
        double height;

        //函数声明
        double get(void);
        void set(double len,double bre,double hei);
};
//成员函数定义
double Box::get(void){
    return length*breadth*height;
}
void Box::set(double len,double bre,double hei){
    length = len;
    breadth =bre;
    height = hei;
}
int main(){
    Box Box1;
    Box Box2;
    double volume =0.0;

    //set box1
    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;

    //set box2
    Box2.height = 10.0;
    Box2.length = 12;
    Box2.breadth = 13;

    volume = Box1.height * Box1.breadth *Box1.length;
    cout << volume << endl;

    Box2.set(10,8,12.0);
    volume = Box2.get();
    cout << volume << endl;
}

```

### 类成员函数

类的成员函数是指那些把定义和原型写在类定义内部的函数，就像类定义中的其他变量一样。类成员函数是类的一个成员，它可以操作类的任意对象，可以访问对象中的所有成员。

成员函数可以定义在类定义内部，或者单独使用**范围解析运算符 ::** 来定义。在类定义中定义的成员函数把函数声明为**内联**的，即便没有使用 inline 标识符。

```cpp
class Box
{
   public:
      double length;      // 长度
      double breadth;     // 宽度
      double height;      // 高度
   
      double getVolume(void)
      {
         return length * breadth * height;
      }
};
```

也可以在类的外部使用**范围解析运算符**.

```cpp
double Box::getVolume(void){
    return length*breadth*height;
}
```

### 类访问修饰符

```cpp
class Base{
    public:
    //公有成员,在程序中类的外部是可访问的
    protected:
    //受保护成员,在类的外部是不可访问的，甚至是不可查看的。只有类和友元函数可以访问私有成员。
    private:
    //私有成员,与私有成员十分相似，但有一点不同，protected（受保护）成员在派生类（即子类）中是可访问的。
}
```

### 构造函数&析构函数

#### 构造函数

类的**构造函数**是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。

构造函数的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回 void。构造函数可用于为某些成员变量设置初始值。

```cpp
#include <iostream>
 
using namespace std;
 
class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line(double len);  // 这是构造函数
 
   private:
      double length;
}
// 构造函数
Line::Line(double len){
    
}
//使用初始化列表
Line::Line( double len): length(len)
{   
}
//上面的语法等效于:
Line::Line( double len)
{
    length = len;
}
//初始化列表语法
C::C( double a, double b, double c): X(a), Y(b), Z(c)
{
  ....
}
```

#### 析构函数

类的**析构函数**是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行。

析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，它不会返回任何值，也不能带有任何参数。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。

```cpp
class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line();   // 这是构造函数声明
      ~Line();  // 这是析构函数声明
 
   private:
      double length;
};
Line::~Line(){
    cout<<"Object is being deleted"<<endl;
}
```

### 拷贝构造函数

拷贝构造函数是一种特殊的构造函数,他在创建对象时,是使用同一类中之前创建的对象来初始化新创建的对象,拷贝构造函数通常用于:

- 使用另一个同类型的对象来初始化新的对象.
- 复制对象把它作为参数传递给函数.
- 复制,并返回这个对象

如果在类中没有定义拷贝构造函数，编译器会自行定义一个。如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数。拷贝构造函数的最常见形式如下：

```cpp
classname (const classname &obj) {
   // 构造函数的主体
}
```

### 友元函数

类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。

友元可以是一个函数，该函数被称为友元函数；友元也可以是一个类，该类被称为友元类，在这种情况下，整个类及其所有成员都是友元。

如果要声明函数为一个类的友元，需要在类定义中该函数原型前使用关键字 **friend**

[示例代码](../code/practice/7_friend.cpp)

### 内联函数

C++ **内联函数**是通常与类一起使用。如果一个函数是内联的，那么在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方。

对内联函数进行任何修改，都需要重新编译函数的所有客户端，因为编译器需要重新更换一次所有的代码，否则将会继续使用旧的函数。

如果想把一个函数定义为内联函数，则需要在函数名前面放置关键字 **inline**，在调用函数之前需要对函数进行定义。如果已定义的函数多于一行，编译器会忽略 inline 限定符。

> Tip： 只有当函数只有 10 行甚至更少时才将其定义为内联函数.
>
> 定义: 当函数被声明为内联函数之后, 编译器会将其内联展开, 而不是按通常的函数调用机制进行调用.
>
> 优点: 当函数体比较小的时候, 内联该函数可以令目标代码更加高效. 对于存取函数以及其它函数体比较短, 性能关键的函数, 鼓励使用内联.
>
> 缺点: 滥用内联将导致程序变慢. 内联可能使目标代码量或增或减, 这取决于内联函数的大小. 内联非常短小的存取函数通常会减少代码大小, 但内联一个相当大的函数将戏剧性的增加代码大小. 现代处理器由于更好的利用了指令缓存, 小巧的代码往往执行更快。
>
> 结论: 一个较为合理的经验准则是, 不要内联超过 10 行的函数. 谨慎对待析构函数, 析构函数往往比其表面看起来要更长, 因为有隐含的成员和基类析构函数被调用!
>
> 另一个实用的经验准则: 内联那些包含循环或 switch 语句的函数常常是得不偿失 (除非在大多数情况下, 这些循环或 switch 语句从不被执行).
>
> 有些函数即使声明为内联的也不一定会被编译器内联, 这点很重要; 比如虚函数和递归函数就不会被正常内联. 通常, 递归函数不应该声明成内联函数.(递归调用堆栈的展开并不像循环那么简单, 比如递归层数在编译时可能是未知的, 大多数编译器都不支持内联递归函数). 虚函数内联的主要原因则是想把它的函数体放在类定义内, 为了图个方便, 抑或是当作文档描述其行为, 比如精短的存取函数.

### this指针

每个对象都有一个特殊的指针 **this**，它指向对象本身。

### 指向类的指针

一个指向 C++ 类的指针与指向结构的指针类似，访问指向类的指针的成员，需要使用成员访问运算符 **->**，就像访问指向结构的指针一样。与所有的指针一样，您必须在使用指针之前，对指针进行初始化。

### 类的静态成员

我们可以使用 **static** 关键字来把类成员定义为静态的。当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。

静态成员在类的所有对象中是共享的。如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。

**不能把静态成员的初始化放置在类的定义中，在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化**

[实例代码](../code/practice/9_static.cpp)

> tips: 构造函数使用public关键字

静态成员函数和普通成员函数的区别:

- 静态成员函数没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）。
- 普通成员函数有this指针,可以访问类中的任意成员;而静态成员函数没有this指针

## c++继承

```cpp
//基类
class Animal{
    // eat()
    // sleep()
}

//派生类,不写访问修饰符,默认是private
class Dog:public Animal{
    //bark()
}
```

语法

```cpp
//access-specifier = public|protected|
class derived-class: access-specifier base-classprivate,access-specifier base-classprivate{
  //派生类类体  
};
```

| 访问     | public | protected | private |
| :------- | :----- | :-------- | :------ |
| 同一个类 | yes    | yes       | yes     |
| 派生类   | yes    | yes       | no      |
| 外部的类 | yes    | no        | no      |

一个派生类继承了所有的基类方法，但下列情况除外：

- 基类的构造函数,析构函数,和拷贝构造函数
- 基类的重载运算符
- 基类的友元函数

## c++重载运算符和重载函数

c++允许在同一个作用域中的某个**函数**和**运算符**指定多个定义,分别称为**函数重载**和**运算符重载**.

重载声明是指一个与之前已经在该作用域内声明过的函数或方法具有相同名称的声明，但是它们的参数列表和定义（实现）不相同。

当您调用一个**重载函数**或**重载运算符**时，编译器通过把您所使用的参数类型与定义中的参数类型进行比较，决定选用最合适的定义。选择最合适的重载函数或重载运算符的过程，称为**重载决策**。
[函数重载示例](../code/practice/10.cpp)

重载的运算符是**带有特殊名称的函数**，函数名是由关键字 operator 和其后要重载的运算符符号构成的。

```cpp
//声明为成员变量
Box operator+(const Box&);
//申明为非成员变量
Box operator+(const Box&, const Box&);
```

[重载运算符示例](./../code/practice/11.cpp)

下面是不可重载的运算符列表：

- `.`：成员访问运算符
- `.`, `->`：成员指针访问运算符
- `::`：域运算符
- `sizeof`：长度运算符
- `?:`：条件运算符
- `#`： 预处理符号

## c++多态

[静态多态示例](../code/practice/12.cpp)

调用函数 area() 被编译器设置为基类中的版本，这就是所谓的**静态多态**，或**静态链接** - 函数调用在程序执行前就准备好了。有时候这也被称为**早绑定**，因为 area() 函数在程序编译期间就已经设置好了。

对程序稍作修改，在 Shape 类中，area() 的声明前放置关键字 **virtual**.

```cpp
class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      virtual int area()
      {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};
//output
//Rectangle class area :
//Triangle class area :
```

### 虚函数

**虚函数** 是在基类中使用关键字 **virtual** 声明的函数。在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到基类函数。

### 纯虚函数

在基类中定义虚函数，但是在基类中又不能对虚函数给出有意义的实现，这个时候就会用到纯虚函数。

```cpp
class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      // pure virtual function
      virtual int area() = 0;
};
```

= 0 告诉编译器，函数没有主体，上面的虚函数是**纯虚函数**。

## ? c++ 数据抽象

// 在c++中,使用访问修饰符定义类的抽象接口

在 C++ 中，我们使用访问标签来定义类的抽象接口。一个类可以包含零个或多个访问标签：

- 使用公共标签定义的成员都可以访问该程序的所有部分。一个类型的数据抽象视图是由它的公共成员来定义的。
- 使用私有标签定义的成员无法访问到使用类的代码。私有部分对使用类型的代码隐藏了实现细节。

访问标签出现的频率没有限制。每个访问标签指定了紧随其后的成员定义的访问级别。指定的访问级别会一直有效，直到遇到下一个访问标签或者遇到类主体的关闭右括号为止。

## c++数据封装

## c++接口(抽象类)

C++ 接口是使用**抽象类**来实现的，抽象类与数据抽象互不混淆，数据抽象是一个把实现细节与相关的数据分离开的概念。

如果类中至少有一个函数被声明为纯虚函数，则这个类就是抽象类。纯虚函数是通过在声明中使用 "= 0" 来指定的.

```cpp
class Box
{
   public:
      // 纯虚函数
      virtual double getVolume() = 0;
   private:
      double length;      // 长度
      double breadth;     // 宽度
      double height;      // 高度
};
```

抽象类不能被用于实例化对象，它只能作为**接口**使用。如果试图实例化一个抽象类的对象，会导致编译错误。

[抽象类示例](../code/practice/13.cpp)

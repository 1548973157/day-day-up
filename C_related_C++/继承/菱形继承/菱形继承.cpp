// 菱形继承.cpp :
//虚继承是C++中的一种特殊继承方式，用于解决菱形继承问题。
/*虚继承机制：虚基类指针 / 表：实现虚继承通常需要编译器在对象中添加额外的指针（或使用虚基类表），用于在运行时动态地定位共享的虚基类子对象的位置。
			本代码示例中，A1和A2中会分别多出来4个字节内存用来存放虚指针。

构造函数调用：虚基类的构造函数由最派生类（在这个例子中是AA）直接调用，而不是由直接继承它的类（A1和A2）调用。
            即使A1和A2的构造函数试图初始化 A，也只有AA的初始化列表中对A的初始化是有效的。
			相当于直接AA调用A的构造函数。
 */

/*
        菱形继承示意图：

               类A(int n)
              /   \
             /     \
  (int n)类A1     类A2（int n）
             \     /
              \   /
              类AA(int n(A1); int n(A2))
    
    ***类A派生出类A1和类A2，类A1和类A2又派生出类AA。
    虚继承作用：当AA继承A1和A2时，编译器会确保AA的对象中只包含一个A子对象。A1和A2都引用这个共享的  A实例，而不是各自拥有一个
*/

#include <iostream>
using namespace std;
/*  不使用虚继承的菱形继承示例
class A {
public:
    int n;
};

class A_1 : public A {
public:
    int a1;
};

class A_2 :public A {
public:
    int a2;
};*/

//虚继承的菱形继承示例
class A {
public:
    int n;
};

class A_1 : virtual public A {
public:
    int a1;
};

class A_2 : virtual public A {
public:
    int a2;
};
class AA :public A_1, public A_2 {
public:
    int aa;
};

//菱形继承使用虚继承
int main()
{
    AA obj_aa;
    obj_aa.aa;
    obj_aa.a1;
    obj_aa.a2;
    obj_aa.n;//虚继承后可以这样用
    obj_aa.A::n; //同上

    return 0;
}
/*菱形继承不使用虚继承
int main()
{
    AA obj_aa;
    obj_aa.aa;
    obj_aa.a1;
    obj_aa.a2;
	//obj_aa.n;//报错原因：二义性，因为类AA继承了类A_1和类A_2，而类A_1和类A_2都继承了类A
    //所以obj_aa中有两个n成员变量，编译器无法确定使用哪个n。
    
    obj_aa.A_1::n;
    obj_aa.A_2::n;//治标不治本
 
    //obj_aa.A::n; // 这行代码会报错，因为AA并没有直接继承A

    return 0;
}

*/


// 构造函数.cpp : 是一种特殊的成员函数；为对象的成员变量赋初始值
//构造函数名和类名相同
//构造函数没有返回值和返回值类型
//构造函数可以重载，需要满足函数重载的条件
#include <iostream>
using namespace std;

class MyClass
{
public:
    const int id;
    const int num;
    const int val;

    /*const成员必须初始化；const 成员必须在所有构造函数中初始化
    如果类成员是另一个类的对象，并且该类没有默认构造函数，必须通过初始化列表初始化
    对于非内置类型（如类对象），使用初始化列表比在构造函数体内赋值更高效*/
    MyClass(int i, int j, int k) :id(i), num(j), val(k) { //初始化列表
        cout << "构造函数（无3参）被调用" << endl;
    }
public:
    MyClass() :id(0), num(0), val(0) {//同名构造函数，重载；const 成员必须在所有构造函数中初始化
        cout << "构造函数（无参）被调用" << endl;
    }
private:

public:
    int a, b;
    MyClass(int i, int j) :id(0), num(0), val(0) { //const 成员必须在所有构造函数中初始化
        a = i;
        b = j;
        cout << "构造函数（有2参）被调用" << endl;
    }
};


int main()
{
    MyClass Object_0;//定义一个类时会自动调用构造函数，不管你有没有定义构造函数
    MyClass Object_1(1, 2);
    MyClass Object_2(1, 2, 3);

    cout << Object_0.num << endl;

    return 0;
}


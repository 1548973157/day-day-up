// 多态.cpp :
//多态的作用：
// 1. 通过父类指针或引用调用子类的虚函数，实现动态绑定
// 2. 通过父类指针或引用调用子类的虚函数，实现代码的复用和扩展
// 3. 通过父类指针或引用调用子类的虚函数，实现接口的统一
// 4. 通过父类指针或引用调用子类的虚函数，实现多态性

#include <iostream>
using namespace std;

class father {
public:
    father();
    virtual ~father();
   virtual void test_func(); // 虚函数
    // 父类指针或引用指向子类对象时，调用子类的虚函数
	// 通过父类指针或引用调用虚函数时，实际调用的是子类的实现
};
class son_1 : public father{
public:
    son_1();
    ~son_1();
    virtual void test_func();
};
class son_2 : public father {
public:
    son_2();
    ~son_2();
    virtual void test_func() ;
};

int main(){
   /*多态的实现
   father* p_fa;

    father obj_fa;
    son_1 obj_ZYL;
	son_2 obj_ZK;

	p_fa = &obj_fa;
	p_fa -> test_func(); // 调用父类的虚函数
	
    p_fa = &obj_ZYL; // 父类指针指向子类对象
    p_fa -> test_func(); // 调用父类的虚函数

    p_fa = &obj_ZK; // 父类指针指向子类对象
    p_fa -> test_func(); // 调用父类的虚函数
    */ 
    father* p_fa = new son_1;
    p_fa->test_func();
	delete p_fa;//运行后只调用了父类的析构函数，子类的析构函数没有调用，导致子类的资源没有释放，出现内存泄漏
	//解决方法：将父类的析构函数声明为虚析构函数
    p_fa = nullptr;

    return 0;
}
/*
多态的条件：
	继承关系
	指针：父类指针或引用指向子类对象
	虚函数

虚函数表：
    每个类都有一个虚函数表，这个表是一个静态数组，其中存储了该类及其基类的所有虚函数的地址。
    虚指针：每个对象如果属于有虚函数的类，则会在对象的内存布局中包含一个指向该类虚函数表的指针
*/

/*** father ***/
father::father()
{
    cout << "父类构造" << endl;
}
void father::test_func()
{
    cout << "father::test_func()" << endl;
}
father::~father()
{
    cout << "父类析构" << endl;
}
/*** son_1 ***/
son_1::son_1()
{
    cout << "子类构造_1" << endl;
}
void son_1::test_func()
{
    cout << "son_1::test_func()" << endl;
}
son_1::~son_1()
{
    cout << "子类析构_1" << endl;
}
/*** son_2 ***/
son_2::son_2()
{
    cout << "子类构造_2" << endl;
}
void son_2::test_func()
{
    cout << "son_2::test_func()" << endl;
}
son_2::~son_2()
{
    cout << "子类析构_2" << endl;
}


// 析构函数.cpp : 
//析构函数是一种特殊的函数；
//    主要作用是在对象生命周期结束时进行清理
//    系统可以自动调用析构函数
//    析构函数没有返回值类型和返回值，也没有参数
//	  不定义系统会默认生成一个，和构造函数一样（低保）
//	  必须公有

/*不是因为调用了析构函数导致生命周期结束。
是生命周期结束时，会自动调用析构函数*/

#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();
};
MyClass::MyClass() {
	cout << "构造函数" << endl;
}
MyClass::~MyClass() {
	cout << "析构函数" << endl;
}	

int main(){
	MyClass obj_0;

}


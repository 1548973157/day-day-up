// const成员.cpp : 

#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass();
	MyClass(int i);
	MyClass(int i, int j);
	~MyClass();

	int num = 0;
	const int val; // const成员变量
	static int n; // static成员变量
public:
	void test_0();
	void test_1()const;// const常成员函数
};

MyClass::MyClass() :val(0) // 初始化const成员变量
{
}
MyClass::MyClass(int i) :val(i)
{
}
MyClass::MyClass(int i,int j) :val(i),num(j)
{
}
MyClass::~MyClass()
{
}

int MyClass::n = 0; // 初始化static成员变量

void MyClass::test_0() {
	cout << "test_0" << endl;
	cout << "val = " << val << endl;
	cout << "num = " << num << endl;
}
void MyClass::test_1() const {
	cout << "test_1" << endl;
	cout << "val = " << val << endl;
	cout << "num = " << num << endl;
	//val = 0;
	//num = 0;
	//this->num = 0;const成员函数中不能修改成员变量，包括const成员变量
	
	n = 1; // 可以修改static成员变量
	this->n = 2; // 可以修改static成员变量
}
int main()
{
	MyClass obj_0; // 使用默认构造函数
	cout << "obj_0.val = " << obj_0.val << endl; // 输出0
	MyClass obj_1(5); //
	cout << "obj_1.val = " << obj_1.val << endl; // 输出5
	
	MyClass obj_2(10, 20);
	obj_2.test_0(); // 输出val=10,num=20
	obj_2.test_1(); // 输出val=10,num=20

	const MyClass obj_3(5, 6);// const常对象
	//obj_3.num = 10; // 错误，const对象不能修改成员变量
	obj_3.n = 10; //可以修改static成员变量
	//obj_3.test_0; // 错误，const对象不能调用非const成员函数
	obj_3.test_1(); // 常对象只能调用const常成员函数

	return 0;
}

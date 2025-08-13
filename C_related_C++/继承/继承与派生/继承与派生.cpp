// 继承与派生.cpp :
//继承是指一个类（子类）从另一个类（父类）获取属性和方法的过程。子类可以继承父类的成员变量和成员函数，并且可以添加自己的成员变量和成员函数。
//派生是指从一个基类创建一个新的类（派生类）的过程。派生类可以重用基类的代码，并且可以扩展或修改基类的功能。

/*
	 A  ===>  B
	父类		子类
	基类	    派生类

	单继承：一个子类只能有一个父类。
		Class 父类名 {};
		Class 子类名 : 继承权限 父类名 {};
	多继承：一个子类可以有多个父类。
		Class 父类名1 {};
		Class 父类名2 {};
		Class 子类名 : 继承权限1 父类名1 {}， 继承权限2 父类名2 {};

	继承权限：
		1.公有继承（public）：子类可以访问父类的公有成员和保护成员，但不能访问父类的私有成员。
		2.保护继承（protected）：子类可以访问父类的公有成员和保护成员，但不能访问父类的私有成员。子类的成员在派生类中变为保护成员。
		3.私有继承（private）：子类不能访问父类的公有成员和保护成员，父类的成员在派生类中变为私有成员。
	注意事项：继承是子类继承全部父类的成员变量和成员函数（区别在于能不能使用），但不能继承父类的构造函数、析构函数和重载运算符。
*/

#include <iostream>
using namespace std;

class father{
public:
	father();
	~father();
private:
	int a;	 
	void pri_func1() {}	//私有成员函数，子类不能访问
protected:
	int b;
	void pro_func2() {}	//保护成员函数，子类可以访问
public:
	int c;
	void pub_func3() {}	//公有成员函数，子类可以访问
};
class son : public father{
public:
	son();
	~son();
	void test() {
		this->c = 0; //子类内部可以访问父类的公有成员
		this->pro_func2(); //子类内部可以访问父类的保护成员函数
		//注意，上面两句是执行操作的语句，不能直接写在类中，要写在函数里
	}

};
/****father****/
father::father() :a(0), b(0), c(0) //初始化成员变量
{
}
father::~father()
{
}
/****son****/
son::son()
{
}
son::~son()
{
}


int main()
{
	cout << "sizeof(father):" << sizeof(father) << endl;
	cout << "sizeof(son):" << sizeof(son) << endl;
	son obj_son;
	obj_son.c = 10; //可以访问父类的公有成员
	obj_son.pub_func3(); //可以访问父类的公有成员函数
	//obj_son.func1();错误，不能访问父类私有成员函数
	return 0;
}

/*
* 继承权限表
				公有继承public			私有继承private			保护继承protected
public			public					private					protected
private			不可访问					不可访问					不可访问
protected		protected				private					protected

*/
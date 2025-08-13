// 派生类和基类.cpp : 


#include <iostream>
using namespace std;

class father_0 {
public:
	father_0();
	~father_0();
	
	int num;
};

class son : public father_0{
public:
	son();
	~son();
	int val;
};

//基类和派生类的关系：
int main() {
	father_0 obj_fat;
	son obj_son;

	obj_fat = obj_son; // 父类对象可以接收子类对象
	// obj_son = obj_fat; // 错误，子类对象不能接收父类对象,因为父类对象不包含子类的特有成员

	father_0* p_fat;
	p_fat = &obj_fat; // 父类指针可以指向父类对象
	p_fat = &obj_son; // 父类指针可以指向子类对象，父类有的子类也有，能读到共有的。 

	son* p_son;
	p_son = &obj_son; // 子类指针可以指向子类对象
	// p_son = &obj_fat; // 错误，子类指针不能指向父类对象,父类对象没有子类特有成员，子类指针范围比父类指针大，读不到特定对象

	return 0;
}

/****father****/
father_0::father_0() {
	num = 0;
	cout << "父类构造" << endl;
}
father_0::~father_0(){
	cout << "父类析构" << endl;
}

/****son****/
son::son() {
	val = 10;
	cout << "子类构造" << endl;
}

son::~son(){
	cout << "子类析构" << endl;
}


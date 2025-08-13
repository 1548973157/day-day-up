// 父子关系.cpp : 


#include <iostream>
using namespace std;

class father_0 {
public:
	father_0();
	~father_0();
	int val;
	int num;
};
class father_1 {
public:
	father_1();
	~father_1();
	int val;
};
class son : public father_0,public father_1 {
public:
	son();
	~son();
	int num;
};

int main(){
	son obj_son;
	cout << "obj_son.num = " << obj_son.num << endl;//子类和父类都有num成员变量，访问的是子类的num
	cout << "obj_son.father_0::num = " << obj_son.father_0::num << endl;//父类名加作用域运算符访问父类的num成员变量
	cout << "obj_son.father_1::val = " << obj_son.father_1::val << endl;//两个父类都有val成员变量

	return 0;
}
/****father****/
father_0::father_0(){
	val = 10;
	num = 20;
}
father_0::~father_0()
{
}
/****father_1****/
father_1::father_1() :val(20){
}
father_1::~father_1() {

}

/****son****/
son::son(){
	num = 99;
}
son::~son()
{
}



/*
* 继承权限表
				公有继承public			私有继承private			保护继承protected
public			public					private					protected
private			不可访问					不可访问					不可访问
protected		protected				private					protected

*/

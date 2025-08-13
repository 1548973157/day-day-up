// 父子类构造函数的关系.cpp : 

#include <iostream>
using namespace std;

class father_0 {
public:
	father_0();
	~father_0();
	father_0(int n); // 带参构造函数
	 const int num;
};

class son : public father_0 {
public:
	son();
	son(int n, int v);
	~son();
	int val;
};

int main() {
	son obj_son; //会先调用父类构造函数，再调用子类构造函数
	cout << "obj_son.num = " << obj_son.num << endl;// 
	cout << "obj_son.val = " << obj_son.val << endl << endl;// 

	son obj_son2(4, 5);
	cout << "obj_son2.num = " << obj_son2.num << endl; // 4
	cout << "obj_son2.val = " << obj_son2.val << endl; // 5
	return 0;
}
/****father****/
father_0::father_0() :num(0){
	cout << "父类构造" << endl;
}
father_0::~father_0() {
	cout << "父类析构" << endl;
}
father_0::father_0(int n) :num(n){
	cout << "父类带参构造" << endl;
}
/****son****/
son::son() {
	val = 10;
	cout << "子类构造" << endl;
}
son::son(int n, int v) : father_0(n) { // 调用父类带参构造函数
	val = v;
	//num = n; // 可以直接在子类中设置父类的成员变量（非const）
	cout << "子类带参构造" << endl;
}
son::~son() {
	cout << "子类析构" << endl;
}


// this指针.cpp :

#include <iostream>
using namespace std;

class MyClass{
	int num;
public:
	void setNum(int num) { //会出现二义性，类成员函数的参数名和成员变量名相同
		
		//num = num;
		this->num = num; //this指针指向当前对象的成员变量
	}
	int getNum() {
		return num;
	}


};

int main()
{
	MyClass obj_0;
	obj_0.setNum(10);
	cout << obj_0.getNum() << endl;
	return 0;
}

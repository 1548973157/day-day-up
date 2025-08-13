// 类与对象.cpp : 
//类是一种用户自定义的数据类型，包含数据成员和成员函数。对象是类的实例化，是类的具体实现。
/*
	class 类名 
	{
	//默认是私有的
		//成员： 1.数据成员（属性） 2.成员函数（方法）
	//修饰符：
	public:									// 公有
		//成员： 1.数据成员（属性） 2.成员函数（方法）

	private:								// 私有，只有类内部可以访问
		//成员： 1.数据成员（属性） 2.成员函数（方法）

	protected:								// 保护，受保护的，类内部和派生类可以访问
		//成员： 1.数据成员（属性） 2.成员函数（方法）
	};
*/
#include <iostream>
using namespace std;

class Personal
{
public:
	char name[20];		// 姓名
private:
	int age;			// 年龄
public:
	void setAge(int n) {
		age = n;
	}
	
	void hobby(){
		cout << "吃了睡，睡了吃" << endl;
	}
	void speak()
	{
		cout << "我叫" << name << "，今年" << age << "岁。" << endl;
	}
private:
	void speakEnglish();
};

void Personal::speakEnglish()
{
	cout << "My name is " << name << ", I am " << age << " years old." << endl;
}//类里面使用，在外面定义



int main()
{
	Personal ZYL;

	strcpy_s(ZYL.name,"赵瑜林");
	ZYL.speak();
	//ZYL.age = 10;错误，age私有属性不能直接访问
	ZYL.setAge(21);
	ZYL.speak();
	return 0;
}


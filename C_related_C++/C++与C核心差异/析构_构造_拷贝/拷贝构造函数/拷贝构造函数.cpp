// 拷贝构造函数.cpp : 
//一种特殊的构造函数，通过拷贝构造函数完成一个复制的过程，和构造、析构一样，都有缺省（低保）
//特殊：参数是本类的对象的引用

//拷贝构造调用时机：
//    使用一个对象给另一个对象初始化
//    使用一个对象构造另一个对象
//    函数的参数是类的对象
//    函数返回值是类的对象

#include <iostream>
using namespace std;

class MyClass
{
    MyClass() {}
    ~MyClass() {}
    MyClass(const MyClass& obj) {}//拷贝
    MyClass(const MyClass& obj,int n) {}//重载拷贝
    MyClass(int i,const MyClass& obj) {}//不是拷贝函数，因为第一个参数不是本类类型的引用
};


class Monster
{
public:
    string name;
    int atk;
    float hp;
public:
    Monster();
    Monster(const char* m_name, int m_atk, float m_hp);
    Monster(const Monster& obj);
    Monster(const Monster& obj,int life);
    ~Monster();//先构造的后析构
    void showData();

};

Monster::Monster() {
    cout << "无参构造" << endl;
    name = "野怪";
    atk  = 200;
    hp   = 100.00f;
}
Monster::Monster(const char* m_name, int m_atk, float m_hp) {
    cout << "带参构造" << endl;
    name = m_name;
    atk  = m_atk;
    hp   = m_hp;
}
Monster::Monster(const Monster& obj) {
    cout << "拷贝构造" << endl;
    name = obj.name;
    atk  = obj.atk;
    hp   = obj.hp;
}
Monster::Monster(const Monster& obj,int life) {
    cout << "重载拷贝构造" << endl;
    name = obj.name;
    atk = obj.atk;
    hp = obj.hp * life;
}
Monster::~Monster() {
    cout << "析构" << endl;
}\
void Monster::showData() {
    cout << "怪物名字：  " << name << endl;
    cout << "怪物攻击力：" << atk <<endl;
    cout << "怪物生命值：" << hp << endl;
    cout << "********" << endl << endl;
}

/**********/
void test1(Monster obj) {
}
Monster test2() {
    Monster obj;
    return obj;
}

/*********/
int main()
{
    /*
    Monster Monster0;
    Monster Monster1("皮卡丘",300,250.00f);
    Monster Monster2 = Monster0; //或者Game Monster2（Monster0）; 
    Monster Monster3(Monster0,10) ;

    Monster* p = new Monster;//这样创建的Monster就是无参，并且不会自动调用析构函数，需要手动delete

    Monster0.showData();
    Monster1.showData();
    Monster2.showData();
    Monster3.showData();
    p->showData();
    delete p;//delete在这里不仅释放内存，同时调用了析构函数
    p = nullptr;
    */
    test2();
    Monster monster = test2();//在这行代码中，test2()返回的是一个临时对象，C++规定临时对象只能绑定到const引用上。所以上面的拷贝函数都要加上const
/*
    运行代码会显示:
        无参构造            或者          无参构造              
        析构                             拷贝构造
        无参构造                         析构
        析构                             析构
                                         无参构造
                                         拷贝构造
                                         析构
                                         析构

前者是因为一些编译器NRVO优化，直接在return创建obj，避免了调用拷贝函数
后者是按流程，1.先Monster了一个obj是构造函数
             2.return obj，因为函数中第一步的obj不会直接返回，所以拷贝一个obj，所以显示拷贝构造
             3.拷贝构造完后，析构拷贝的obj
             4.析构
             
*/                                      
    return 0;
}

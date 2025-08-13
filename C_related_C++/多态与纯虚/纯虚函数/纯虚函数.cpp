// 纯虚函数.cpp : 
//抽象类：包含纯虚函数的类，不能被实例化。
//纯虚函数是没有实现的虚函数，必须在派生类中实现。

#include <iostream>
using namespace std;

// 抽象基类
class Animal {
public:
    // 纯虚函数：叫
    virtual void speak() = 0;  // 只声明，不实现
    Animal();
    virtual ~Animal(); // 虚析构函数，确保派生类正确析构
};

// 派生类：狗
class Dog : public Animal {
public:
    void speak() override {
        cout << "汪汪！" << endl;
    }
    Dog();
    ~Dog();
};

// 派生类：猫
class Cat : public Animal {
public:
    void speak() override {
        cout << "喵喵！" << endl;
    }
	Cat();
	~Cat();
};

int main() {
    // Animal a;     // ❌ 错误：不能实例化抽象类

    Animal* pet;

    pet = new Dog();
    pet->speak();   // 输出：汪汪！
    delete pet;

    pet = new Cat();
    pet->speak();   // 输出：喵喵！
    delete pet;

    return 0;
}

Animal::Animal() {
    cout << "Animal构造函数" << endl;
}
Animal::~Animal() {
    cout << "Animal析构函数" << endl;
}

Dog::Dog() {
    cout << "Dog构造函数" << endl;
}
Dog::~Dog() {
    cout << "Dog析构函数" << endl;
}

Cat::Cat() {
    cout << "Cat构造函数" << endl;
}
Cat::~Cat() {
    cout << "Cat析构函数" << endl;
}
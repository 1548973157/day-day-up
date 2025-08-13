// 函数重载.cpp :
/*
    同名函数：多个函数使用相同的名称
    参数不同：参数的类型、数量或顺序必须不同
    返回值不参与重载：仅返回值类型不同不能构成重载
    编译时确定：编译器根据调用时的实参选择最匹配的函数
*/

#include <iostream>
using namespace std;  // 引入 std 命名空间
void print(int i) {
    cout << "整数: " << i << endl;
}

void print(float f) {
    cout << "单精度: " << f << endl;
}

void print(double lf) {
    cout << "双精度: " << lf << endl;
}

void print(const char* s) {
    cout << "字符串: " << s << endl;
}
int main()
{
	print(10);
    print(10.12f);
    print(10.12);
    print("ABC");
	//函数名可以一致，但参数类型、数量或顺序必须不同

}



// String类.cpp :

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str,str1;
    str = "abc123";
    str1 = "ABC123";
    std::cout << "str = " << str <<endl;
    char ch = str[2];
    std::cout << "ch = " << ch << endl;
    ch = str.at(3);
    std::cout << "ch = " << ch << endl;

    //str.length();//求长度
    std::cout << "str长度为  " << str.length() << endl;

    //str.clear();清空字符串内容
    str.clear();
    std::cout << "str = " << str << endl;

    //str.empty();判断字符串是否为空
    std::cout << "str1字符串为空  " << str.empty() << endl;

    //str == str1;//比较两个字符串是否相等（区分大小写）
    std::cout << "str1与str相等  " << (str == str1) << endl;

    return 0;
}


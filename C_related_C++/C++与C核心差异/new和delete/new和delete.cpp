// new和delete.cpp : 
//new类似于malloc，delete类似于free

//malloc和free是C语言中的函数，new和delete是C++中的关键字
#include <iostream>
using namespace std;
int main()
{
	//申请单个内存
	int* p1 = new int; //申请一个int类型的内存空间
	*p1 = 10; //给这个内存空间赋值
	cout << "*p1: " << *p1 << endl;

	//申请单个内存并初始化
	int* p2 = new int(20); //申请一个int类型的内存空间并初始化为20
	cout << "*p2: " << *p2 << endl;

	//批量申请内存（连续内存）
	int* p3 = new int[10];
	for (size_t i = 0; i < 10; i++) //size_t 是无符号类型，适合表示大小和索引比，能表示足够大的正数。
	{
		p3[i] = i;
		cout << "p3["<<i<<"] = " << p3[i] <<"\t";
	}

	delete p1; //释放p1指向的内存
	delete p2; //释放p2指向的内存
	delete[] p3; //连续释放p3指向的内存

	
	return 0;
}



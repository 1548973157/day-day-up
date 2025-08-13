/*跳转语句，执行跳出，或跳转的功能
break
作用于switch和循环语句中，用于跳出当前的switch语句或当前的循环语句
只能跳出一重switch或循环
continue
只作用于循环，用来结束当前循环，进入下一次循环
下一次循环要注意，如果是for，是先到表达式3，再判断下一次循环
goto 慎用
C语言中不限制程序中使用标号的次数，goto又可以无条件的跳转到标号处，所以可能导致代码的混乱
*/
#include <stdio.h>
int main(){
	//for演示break，找到5跳出
	for(int i=0;i<10;i++){
		if(i==5){
			printf("找到了\n");
			break;//跳出循环
		}
		printf("%d\n",i);
	}
	
	for(int j=0;j<10;j++){
		if(j%2==0){//表示偶数
			printf("找到了\n");
			continue;//跳转，在for里会先到表达式3 再回到循环条件
			printf("%d\n",j);
		}
	}
	
	/*
	int k=0;
	MYLAB://标签,冒号修饰
	printf("%d\n",++k);
	goto MYLAB;
	死循环
	*/
	return 0;	
}

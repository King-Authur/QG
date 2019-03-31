#include <stdio.h>
#include <stdlib.h>
#include"SqStack.h"
int main()
{
	int choose=0,sizes=0;
	SqStack node;
	SqStack *s=&node;
	printf("How large would you like(the stack)?\nPlese enter :");
	while(scanf("%d",&sizes)!=1)
	{
		printf("Wrong input,please enter again\n");
		while(getchar()!='\n');
	}
	initStack(s,sizes);
	
	while(choose=menu(s))
	{
		switch(choose)
		{
			case 1://初始化栈
				printf("How large would you like?\nPlese enter :");
				while(scanf("%d",&sizes)!=1)
				{
					printf("Wrong input,please enter again\n");
					while(getchar()!='\n');
				}
				initStack(s,sizes);
				break;
			case 2://判断栈是否为空
				if(isEmptyStack(s))
					printf("It is empty\n");
				else
					printf("It is not empty\n");
				break; 
			case 3://得到栈顶元素
				getTopStack(s,s->elem);
				break;
			case 4://清空栈
				clearStack(s);
				break;
			case 5://销毁栈
				destroyStack(s);
				break;
			case 6://检测栈长度
				stackLength(s,s->top);
			case 7://入栈
				printf("Please enter the data you want to push into the stack:");
				int num;
				while(scanf("%d",&num)!=1)
				{
					printf("Wrong input\nPlease enter again\n");
					while(getchar()!='\n');
				}
				pushStack(s,num);
				break;
			case 8://出栈
				popStack(s,s->top);
				break;
		}
	}
	return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>
//数组实现栈 
int *arrp=NULL;
int cnt=0;//栈实际储存的元素个数 
//压栈 
int push(int num){
	arrp[cnt++]=num;
	return 0;
}
//弹栈 
int pop(){
	return arrp[--cnt];
}
//取栈顶 
void pick(){
	printf("%d\n",arrp[cnt-1]);
}
//判断是否为空 
int empty(){
	return cnt; 
}
//输出
int put_out(){
	int i=cnt-1;
	while(i>=0)
		printf("%d	",arrp[i--]);
	printf("\n");
} 
//创建 
int creat(){
	int size,num;
	cnt=0;
	printf("输入栈的大小:"); 
	scanf("%d",&size);
	arrp=(int*)malloc(size*sizeof(int));
	printf("输入数据(输入0以结束输入)：");
	while(scanf("%d",&num)&&cnt<size&&num!=0)
		push(num);
	return 0;
}
//销毁 
int destroy(){
	free(arrp);
	arrp=NULL;
	return 0;
}
int menu(){
	int num;
	printf("\n-----功能-----\n");
	printf("1、创建\n");
	printf("2、销毁\n");
	printf("3、压栈\n");
	printf("4、弹栈\n");
	printf("5、取栈顶\n");
	printf("6、是否为空\n");
	printf("7、输出\n");
	printf("输入0以退出程序\n"); 
	printf("----------------\n");
	scanf("%d",&num);
	return num;
}
*/

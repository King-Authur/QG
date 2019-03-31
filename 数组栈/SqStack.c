#include"SqStack.h"
#include<stdbool.h>
#include <stdlib.h>
//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
{
	s->size=sizes;
	s->top=-1;
	(s->elem)=(ElemType*)malloc(sizeof(ElemType)*sizes);
	return SUCCESS;
}
Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
	if(s->top==-1)
		return SUCCESS;	
	return ERROR;
}
Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
	if(s->top>=0)
	{
		printf("栈顶元素为：%d\n",e[s->top]);
		return SUCCESS;
	}
	printf("ERROR\n");
	return ERROR;
}
Status clearStack(SqStack *s)   //清空栈
{
	s->top=-1;
	printf("We have clear it successfully\n");
	return SUCCESS;
}
Status destroyStack(SqStack *s)  //销毁栈
{
	while(s->size>=0)
	{
		free((s->elem));
		s->top=-1;
	}
	printf("We have already destroy it\n");
	return SUCCESS;
}
Status stackLength(SqStack *s,int *length)   //检测栈长度
{
	length=s->top;
	printf("It is lenth is %d\n",length);
	return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)  //入栈
{
	(s->elem)[++(s->top)]=data;
	printf("Successfully did it\n");
	return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)   //出栈
{
	data--;
	printf("We have pop it out of the stack\n");
	return SUCCESS;
}
int menu(SqStack *s)
{
	int choose;
	printf("	******数组栈的实现******	\n");
	printf("1、初始化栈\n");
	if(s->top!=-1)
	{
		printf("2、判断栈是否为空\n");	
		printf("3、得到栈顶元素\n");
		printf("4、清空栈\n");
		printf("5、销毁栈\n");
		printf("6、检测栈长度\n");	
	}
	printf("7、入栈\n");
		
	if(s->top!=-1)
		printf("8、出栈\n");
		
	printf("Please enter your choose\n");
	while(scanf("%d",&choose)!=1||(s->top==-1&&choose!=1&&choose!=7))
	{
	 	printf("错误输入\n");
	 	while(getchar()!='\n');
	}
	return choose;
}


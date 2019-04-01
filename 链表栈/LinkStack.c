#include"LinkStack.h"
#include<stdlib.h>
//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
	s=(LinkStack*)malloc(sizeof(LinkStack));  //wrong
	s->top=p;
	s->count=0;
	return SUCCESS*printf("Successfully did it\n");
}
Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
	if(s->count==0)
		return SUCCESS*printf("It is empty\n");
	return ERROR*printf("It is not empty\n"); 
}
Status getTopLStack(LinkStack *s)  //得到栈顶元素
{
	if(s->count>0)
		return SUCCESS*printf("The top factor of the stack is %d\n",s->top->data);
	return ERROR*printf("It is empty\n");
}
Status clearLStack(LinkStack *s)   //清空栈
{	
	LinkStackPtr p=s;
	while(s->count)
	{
		p=s->top->next;
		free(s->top);
		s->count--;
		s=p;
	}
	return SUCCESS*printf("We have successfully cleaned it\n");
}
Status destroyLStack(LinkStack *s)   //销毁栈
{
	LinkStackPtr p=s;
	while(s->count)
	{
		p=s->top->next;
		free(s->top);
		s->count--;
		s=p;
	}
	return SUCCESS*printf("We have successfully destroy it\n");
}
Status LStackLength(LinkStack *s)    //检测栈长度
{
	return SUCCESS*printf("%d\n",s->count);
}
Status pushLStack(LinkStack *s,ElemType data)   //入栈
{
	LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
	p->data=data;
	p->next=s->top;
	s->top=p;
	s->count++;
	return SUCCESS*printf("Succeed\n");
}
Status popLStack(LinkStack *s)   //出栈
{
	LinkStackPtr p=s->top->next;
	free(s->top);
	s->top=p;
	s->count--;
	return SUCCESS*printf("Succeed\n");
}
int menu(LinkStack *s)
{
	int choose;
	
		printf("	******链表栈的实现******	\n");
		printf("1、初始化栈(It will cover the old stack)\n");
		printf("2、判断栈是否为空\n");	
		printf("3、得到栈顶元素\n");
		printf("4、清空栈\n");
		printf("5、销毁栈\n");
		printf("6、检测栈长度\n");	
		printf("7、入栈\n");
		printf("8、出栈\n");
		printf("0、退出程序\n");
		printf("	******链表栈的实现******	\n");
		printf("Please enter your choose\n");
	
	while(scanf("%d",&choose)!=1||(s==NULL&&choose!=1&&choose!=0))
	{
	 	printf("错误输入\n");
	 	while(getchar()!='\n');
	}
	return choose;
}

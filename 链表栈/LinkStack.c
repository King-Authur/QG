#include"LinkStack.h"
#include<stdlib.h>
//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
	s=(LinkStack*)malloc(sizeof(LinkStack));  //wrong
	s->top=p;
	s->count=0;
	return SUCCESS*printf("Successfully did it\n");
}
Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
	if(s->count==0)
		return SUCCESS*printf("It is empty\n");
	return ERROR*printf("It is not empty\n"); 
}
Status getTopLStack(LinkStack *s)  //�õ�ջ��Ԫ��
{
	if(s->count>0)
		return SUCCESS*printf("The top factor of the stack is %d\n",s->top->data);
	return ERROR*printf("It is empty\n");
}
Status clearLStack(LinkStack *s)   //���ջ
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
Status destroyLStack(LinkStack *s)   //����ջ
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
Status LStackLength(LinkStack *s)    //���ջ����
{
	return SUCCESS*printf("%d\n",s->count);
}
Status pushLStack(LinkStack *s,ElemType data)   //��ջ
{
	LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
	p->data=data;
	p->next=s->top;
	s->top=p;
	s->count++;
	return SUCCESS*printf("Succeed\n");
}
Status popLStack(LinkStack *s)   //��ջ
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
	
		printf("	******����ջ��ʵ��******	\n");
		printf("1����ʼ��ջ(It will cover the old stack)\n");
		printf("2���ж�ջ�Ƿ�Ϊ��\n");	
		printf("3���õ�ջ��Ԫ��\n");
		printf("4�����ջ\n");
		printf("5������ջ\n");
		printf("6�����ջ����\n");	
		printf("7����ջ\n");
		printf("8����ջ\n");
		printf("0���˳�����\n");
		printf("	******����ջ��ʵ��******	\n");
		printf("Please enter your choose\n");
	
	while(scanf("%d",&choose)!=1||(s==NULL&&choose!=1&&choose!=0))
	{
	 	printf("��������\n");
	 	while(getchar()!='\n');
	}
	return choose;
}

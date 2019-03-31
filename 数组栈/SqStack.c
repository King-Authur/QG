#include"SqStack.h"
#include<stdbool.h>
#include <stdlib.h>
//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
{
	s->size=sizes;
	s->top=-1;
	(s->elem)=(ElemType*)malloc(sizeof(ElemType)*sizes);
	return SUCCESS;
}
Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
	if(s->top==-1)
		return SUCCESS;	
	return ERROR;
}
Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
{
	if(s->top>=0)
	{
		printf("ջ��Ԫ��Ϊ��%d\n",e[s->top]);
		return SUCCESS;
	}
	printf("ERROR\n");
	return ERROR;
}
Status clearStack(SqStack *s)   //���ջ
{
	s->top=-1;
	printf("We have clear it successfully\n");
	return SUCCESS;
}
Status destroyStack(SqStack *s)  //����ջ
{
	while(s->size>=0)
	{
		free((s->elem));
		s->top=-1;
	}
	printf("We have already destroy it\n");
	return SUCCESS;
}
Status stackLength(SqStack *s,int *length)   //���ջ����
{
	length=s->top;
	printf("It is lenth is %d\n",length);
	return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)  //��ջ
{
	(s->elem)[++(s->top)]=data;
	printf("Successfully did it\n");
	return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)   //��ջ
{
	data--;
	printf("We have pop it out of the stack\n");
	return SUCCESS;
}
int menu(SqStack *s)
{
	int choose;
	printf("	******����ջ��ʵ��******	\n");
	printf("1����ʼ��ջ\n");
	if(s->top!=-1)
	{
		printf("2���ж�ջ�Ƿ�Ϊ��\n");	
		printf("3���õ�ջ��Ԫ��\n");
		printf("4�����ջ\n");
		printf("5������ջ\n");
		printf("6�����ջ����\n");	
	}
	printf("7����ջ\n");
		
	if(s->top!=-1)
		printf("8����ջ\n");
		
	printf("Please enter your choose\n");
	while(scanf("%d",&choose)!=1||(s->top==-1&&choose!=1&&choose!=7))
	{
	 	printf("��������\n");
	 	while(getchar()!='\n');
	}
	return choose;
}


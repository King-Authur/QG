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
			case 1://��ʼ��ջ
				printf("How large would you like?\nPlese enter :");
				while(scanf("%d",&sizes)!=1)
				{
					printf("Wrong input,please enter again\n");
					while(getchar()!='\n');
				}
				initStack(s,sizes);
				break;
			case 2://�ж�ջ�Ƿ�Ϊ��
				if(isEmptyStack(s))
					printf("It is empty\n");
				else
					printf("It is not empty\n");
				break; 
			case 3://�õ�ջ��Ԫ��
				getTopStack(s,s->elem);
				break;
			case 4://���ջ
				clearStack(s);
				break;
			case 5://����ջ
				destroyStack(s);
				break;
			case 6://���ջ����
				stackLength(s,s->top);
			case 7://��ջ
				printf("Please enter the data you want to push into the stack:");
				int num;
				while(scanf("%d",&num)!=1)
				{
					printf("Wrong input\nPlease enter again\n");
					while(getchar()!='\n');
				}
				pushStack(s,num);
				break;
			case 8://��ջ
				popStack(s,s->top);
				break;
		}
	}
	return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>
//����ʵ��ջ 
int *arrp=NULL;
int cnt=0;//ջʵ�ʴ����Ԫ�ظ��� 
//ѹջ 
int push(int num){
	arrp[cnt++]=num;
	return 0;
}
//��ջ 
int pop(){
	return arrp[--cnt];
}
//ȡջ�� 
void pick(){
	printf("%d\n",arrp[cnt-1]);
}
//�ж��Ƿ�Ϊ�� 
int empty(){
	return cnt; 
}
//���
int put_out(){
	int i=cnt-1;
	while(i>=0)
		printf("%d	",arrp[i--]);
	printf("\n");
} 
//���� 
int creat(){
	int size,num;
	cnt=0;
	printf("����ջ�Ĵ�С:"); 
	scanf("%d",&size);
	arrp=(int*)malloc(size*sizeof(int));
	printf("��������(����0�Խ�������)��");
	while(scanf("%d",&num)&&cnt<size&&num!=0)
		push(num);
	return 0;
}
//���� 
int destroy(){
	free(arrp);
	arrp=NULL;
	return 0;
}
int menu(){
	int num;
	printf("\n-----����-----\n");
	printf("1������\n");
	printf("2������\n");
	printf("3��ѹջ\n");
	printf("4����ջ\n");
	printf("5��ȡջ��\n");
	printf("6���Ƿ�Ϊ��\n");
	printf("7�����\n");
	printf("����0���˳�����\n"); 
	printf("----------------\n");
	scanf("%d",&num);
	return num;
}
*/

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
				break;
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


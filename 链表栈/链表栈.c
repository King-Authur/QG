#include <stdio.h>
#include <stdlib.h>
#include"LinkStack.h"

int main()
{
	LinkStack node;
	LinkStack*s=&node;//ջ��ָ�� 
	int choose=1;
	while(choose)
	{
		switch(choose=menu(s))
		{
			case 1://��ʼ��ջ
				initLStack(s);
				break;
			case 2://�ж�ջ�Ƿ�Ϊ��
				isEmptyLStack(s);
				break; 
			case 3://�õ�ջ��Ԫ��
				getTopLStack(s);
				break;
			case 4://���ջ
				clearLStack(s);
				break;
			case 5://����ջ
				destroyLStack(s);
				break;
			case 6://���ջ����
				LStackLength(s);
				break;
			case 7://��ջ
				printf("Enter the num you want to put into the stack\n");
				int data;
				while(scanf("%d",&data)!=1)
				{
					printf("Wrong input\n");
					while(getchar()!='\n');
				}
				pushLStack(s,data);
				break;
			case 8:
				popLStack(s);
				break;
			case 0:
				return 0*printf("Thanks for your using\n"); 
		}
	 } 
	
	return 0;
}

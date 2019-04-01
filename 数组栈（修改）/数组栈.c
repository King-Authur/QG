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
				break;
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


#include <stdio.h>
#include <stdlib.h>
#include"LinkStack.h"

int main()
{
	LinkStack node;
	LinkStack*s=&node;//栈顶指针 
	int choose=1;
	while(choose)
	{
		switch(choose=menu(s))
		{
			case 1://初始化栈
				initLStack(s);
				break;
			case 2://判断栈是否为空
				isEmptyLStack(s);
				break; 
			case 3://得到栈顶元素
				getTopLStack(s);
				break;
			case 4://清空栈
				clearLStack(s);
				break;
			case 5://销毁栈
				destroyLStack(s);
				break;
			case 6://检测栈长度
				LStackLength(s);
				break;
			case 7://入栈
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

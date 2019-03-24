#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"				
Node*head=NULL;
int main(int argc, char *argv[]) {
	int run=1;
	while(run)
	{
		switch(run=menu())
		{
			case 0:
				printf("感谢使用，祝您生活愉快\n"); 
				break;
			case 1:
				head=CreatList();
				break;
			case 2:
				search(head);
				break;
			case 3:
				alter(head);
				break;
			case 4:
				head=insert(head);
				break;
			case 5:
				head=delet(head); 
				break;
			case 6:
				head=destory(head);
				break;
			case 7:
				output(head);
				break;
			case 8:
				search_middle(head);
				break;
			case 9:
				head=reversal(head);
				break;
			default:
				rewind(stdin);
				printf("输入有误，请重新输入!\n");
				break;
		}
	}
	return 0;
}

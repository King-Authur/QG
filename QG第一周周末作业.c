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
				printf("��лʹ�ã�ף���������\n"); 
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
				printf("������������������!\n");
				break;
		}
	}
	return 0;
}

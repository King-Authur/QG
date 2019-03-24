#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//实现动态双向链表
int len,run=1;
typedef struct node
{
	struct node*pri;
 	int data;
 	struct node*next;
}Node;
void output(Node*p)///输出链表 
{
	for(;p!=NULL;p=p->next)
		printf("%d	",p->data);
	printf("\n"); 
} 
Node *CreatList()//增加数据直到输入0
{
	printf("输入0以结束链表的创建\n");
	Node *head,*p1,*p2;
	p1=p2=(Node*)malloc(sizeof(Node));
	for(head=NULL,len=0;scanf("%d",&p1->data),p1->data!=0;)
	{
		len++;
		if(len==1)
		{
			head=p1;
			head->pri=NULL;
		}
		else{
			p1->pri=p2;
			p2->next=p1;
			p2=p1;
		}
		p1=(Node*)malloc(sizeof(Node));
	}
	p2->next=NULL;
	return head;
}
void search(Node*p)//查找节点 
{
	printf("输入要查找的数据：");
	int num,flag=0; 
	scanf("%d",&num); 
	while(p->data!=num)
	{
		if(p->data==num)
			flag=1;
		p=p->next;
	}
	if(flag==1)
		printf("查找结果:该信息存在\n");
	else
		printf("查找结果:该信息不存在\n");
}
void alter(Node*p)//修改节点 
{
	printf("输入要修改的数据的位置：");
	printf("输入新的数据：");
	int posi,num;
	scanf("%d %d",&posi,&num);
	for(int i=1;i<posi;i++)
		p=p->next;
	p->data=num;
} 
Node* insert(Node*p1)//插入某个值
{
	printf("输入要插入的数据：");
	Node* p2=(Node*)malloc(sizeof(Node));
	int num;
	scanf("%d",&p2->data);
	p2->next=p1;
	p2->pri=NULL;
	if(p1!=NULL) 
		p1->pri=p2;
	p1=p2;
	return p1;
} 
Node* delet(Node*p)//删除节点 
{
	printf("输入要删除的数据：");
	int num;
	scanf("%d",&num); 
	Node*head=p,*tem=p;
	while(p!=NULL)
	{
		if(p->data==num&&p==head)
		{
			head=p->next;
			head->pri=NULL;
			free(p);
			tem=p=head;
		}
		else if(p->data==num)
		{
			p->pri->next=p->next;
			if(p->next!=NULL)
				p->next->pri=p->pri;
			free(p);
			p=tem;
		}
		else
		{
			tem=p;
			p=p->next;
		}
	}
	return head;
}
Node* destory(Node* p)//销毁链表 
{
	while(p!=NULL&&p->next!=NULL)
	{
		p=p->next;
		free(p->pri);
	}
	free(p);
	return NULL;
}
int menu()//菜单 
{
	printf("\n------功能表------\n");
	printf("1、创建链表\n");
	printf("2、查找节点\n");
	printf("3、修改节点\n");
	printf("4、插入节点\n");
	printf("5、删除节点\n");
	printf("6、清空链表\n");
	printf("7、打印链表\n");
	printf("输入0以退出程序\n------------------\n");
	printf("请输入要使用的功能(数字):");
	int num;
	scanf("%d",&num);
	return num;
}
int main()
{
	Node*head=NULL;
	while(run)
	{
		switch(run=menu())
		{
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
			default:
				break;
		}
	}
	return 0;
} 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//ʵ�ֶ�̬˫������
int len,run=1;
typedef struct node
{
	struct node*pri;
 	int data;
 	struct node*next;
}Node;
void output(Node*p)///������� 
{
	for(;p!=NULL;p=p->next)
		printf("%d	",p->data);
	printf("\n"); 
} 
Node *CreatList()//��������ֱ������0
{
	printf("����0�Խ�������Ĵ���\n");
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
void search(Node*p)//���ҽڵ� 
{
	printf("����Ҫ���ҵ����ݣ�");
	int num,flag=0; 
	scanf("%d",&num); 
	while(p->data!=num)
	{
		if(p->data==num)
			flag=1;
		p=p->next;
	}
	if(flag==1)
		printf("���ҽ��:����Ϣ����\n");
	else
		printf("���ҽ��:����Ϣ������\n");
}
void alter(Node*p)//�޸Ľڵ� 
{
	printf("����Ҫ�޸ĵ����ݵ�λ�ã�");
	printf("�����µ����ݣ�");
	int posi,num;
	scanf("%d %d",&posi,&num);
	for(int i=1;i<posi;i++)
		p=p->next;
	p->data=num;
} 
Node* insert(Node*p1)//����ĳ��ֵ
{
	printf("����Ҫ��������ݣ�");
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
Node* delet(Node*p)//ɾ���ڵ� 
{
	printf("����Ҫɾ�������ݣ�");
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
Node* destory(Node* p)//�������� 
{
	while(p!=NULL&&p->next!=NULL)
	{
		p=p->next;
		free(p->pri);
	}
	free(p);
	return NULL;
}
int menu()//�˵� 
{
	printf("\n------���ܱ�------\n");
	printf("1����������\n");
	printf("2�����ҽڵ�\n");
	printf("3���޸Ľڵ�\n");
	printf("4������ڵ�\n");
	printf("5��ɾ���ڵ�\n");
	printf("6���������\n");
	printf("7����ӡ����\n");
	printf("����0���˳�����\n------------------\n");
	printf("������Ҫʹ�õĹ���(����):");
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

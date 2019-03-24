#include<stdio.h>
#include<stdlib.h> 
#include "linkedList.h"
int len;
Node *CreatList()
{
	printf("����0�Խ�������Ĵ���\n");
	Node *head,*p1,*p2;
	p1=p2=(Node*)malloc(sizeof(Node));
	for(head=NULL,len=0;scanf("%d",&p1->score)&&p1->score!=0;)
	{
		len++;
		if(len==1)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(Node*)malloc(sizeof(Node));
	}
	p2->next=NULL;
	printf("�ɹ���������\n");
	output(head); 
	return head;
}

/**
 *  @name        : Node* destory(Node* p);
 *	@description : destroy the list, free all the nodes
 *	@param		 : p(the head pointer)
 *	@return		 : None
 *  @notice      : None
 */
Node* destory(Node* p)
{
	Node*tem=p;
	while(p!=NULL){
		p=tem->next;
		free(tem);
		tem=p;
	}
	len=0;
	return p;
}

/**
 *  @name        : Node* insert(Node*head);
 *	@description : insert node q in the end of the list
 *	@param		 : p(head pointer)
 *	@return		 : None
 *  @notice      : None
 */
Node* insert(Node*head)
{
	Node*p;
	p=(Node*)malloc(sizeof(Node));
	p->next=head;
	head=p;
	printf("����һ��Ҫ�������Ϣ:");
	scanf("%d",&head->score);
	printf("��Ϣ����ɹ�\n");
	len++; 
	return head;
} 

/**
 *  @name        : Node* delet(Node*p);
 *	@description : delete the node in the position as user requestion
 *	@param		 : p(head pointer)
 *	@return		 : None
 *  @notice      : None
 */
Node* delet(Node*p)
{
	printf("����Ҫɾ������Ϣ:");
	int num;
	scanf("%d",&num);
	Node*head,*tem;
	head=tem=p; 
	while(p!=NULL){
		if(p->score==num&&p==head){
			head=p->next;
			free(p);
			tem=p=head;
			len--;
		}
		else if(p->score==num) {
			tem->next=p->next;
			free(p);
			p=tem->next;
			len--; 
		}
		else{
			tem=p;
			p=p->next;
			len--;
		}
	}
	return head;
}

/**
 *  @name        : void alter(Node*p);
 *	@description : change the node 
 *	@param		 : p(head pointer)
 *	@return		 : None
 *  @notice      : None
 */
void alter(Node*p)
{
	int posi,num;
	output(p);
	printf("������Ҫ�޸Ľڵ��λ�ã�");
	printf("����Ҫ�޸ĵ�ֵ��");
	while (1)
	{
		scanf("%d %d",&posi,&num);
		if(posi>=0&&posi<=len)
			break;
		else
			printf("������������������\n"); 
	}
	while(--posi)
		p=p->next;
	p->score=num;
	printf("��Ϣ�޸ĳɹ�\n"); 
}

/**
 *  @name        : void output(Node*p);
 *	@description : out put all factors in the list
 *	@param		 : p(the head pointer)
 *	@return		 : None
 *  @notice      : None
 */
void output(Node*p)
{
	while(p!=NULL)
	{
		printf("%d ",p->score);
		p=p->next;
	}
	printf("\n");
} 

/**
 *  @name        : void search(Node*p);
 *	@description : search the node in the list and response it is exit or not
 *	@param		 : p(the head pointer)
 *	@return		 : None
 *  @notice      : None
 */
void search(Node*p)
{
	int num,flag=0;
	printf("����Ҫ��ѯ�ĳɼ���");
	scanf("%d",&num);
	while(p!=NULL)
	{
		if(p->score==num){
			flag=1;
			break;
		}
		p=p->next;
	}
	if(flag==1)
		printf("��ѯ���:����Ϣ����\n");
	else
		printf("��ѯ���:����Ϣ������\n");
}


/**
 *  @name        : Node* reversal(Node *head);
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : p(the head pointer)
 *	@return		 : (the new head pointer)
 *  @notice      : choose to finish 
 */
Node* reversal(Node *head)
{
	Node*p=head,*p_tem=NULL;
	while(p!=NULL&&p->next!=NULL){
		if(p==head){
			head=head->next;
			p->next=head->next;
			head->next=p;
		}
		else{
			p_tem->next=p->next;
			p->next=p->next->next;
			p_tem->next->next=p;
		}
		p_tem=p;
		p=p->next;
	}
	return head;
}

/**
 *  @name        : int search_middle(Node*p);
 *	@description : find the middle node in the linked list,and show the middle node's data
 *	@param		 : p(the head pointer)
 *	@return		 : zero or not
 *  @notice      : choose to finish 
 */
int search_middle(Node*p)
{
	if(p==NULL)//����Ϊ�յ�ʱ������  
		return 0;
	Node*fast=p;
	Node*slow=p;
	while(fast->next!=NULL&&fast->next->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	/*������������ڵ㣬��ôslow�����е㡣ż��������slow����һ��*/
	if(fast->next!=NULL)//ż���� 
		printf("�����е��ֵΪ��%d	%d	\n\n",slow->score,slow->next->score);
	else
		printf("�����е��ֵΪ��%d	\n\n",slow->score);
	return 0;
} 

/**
 *  @name        : int menu();
 *	@description : present the functions of the program  
 *	@param		 : None
 *	@return		 : user's choose
 *  @notice      : None
 */ 
 int menu()
{
	printf("\n------���ܱ�------\n");
	printf("1����������(������Ḳ�Ǿ�����Ŷ)\n");
	printf("2�����ҽڵ�\n");
	printf("3���޸Ľڵ�\n");
	printf("4������ڵ�\n");
	printf("5��ɾ���ڵ�\n");
	printf("6���������\n");
	printf("7����ӡ����\n");
	printf("8�����������е�\n"); 
	printf("9����ת��żλ�õĽڵ�\n"); 
	printf("����0���˳�����\n------------------\n");
	printf("������Ҫʹ�õĹ���(����):");
	int num;
	scanf("%d",&num);
	return num;
}

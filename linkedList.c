#include<stdio.h>
#include<stdlib.h> 
#include "linkedList.h"
int len;
Node *CreatList()
{
	printf("输入0以结束链表的创建\n");
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
	printf("成功创建链表：\n");
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
	printf("输入一个要插入的信息:");
	scanf("%d",&head->score);
	printf("信息插入成功\n");
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
	printf("输入要删除的信息:");
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
	printf("输入所要修改节点的位置：");
	printf("输入要修改的值：");
	while (1)
	{
		scanf("%d %d",&posi,&num);
		if(posi>=0&&posi<=len)
			break;
		else
			printf("输入有误，请重新输入\n"); 
	}
	while(--posi)
		p=p->next;
	p->score=num;
	printf("信息修改成功\n"); 
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
	printf("输入要查询的成绩：");
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
		printf("查询结果:该信息存在\n");
	else
		printf("查询结果:该信息不存在\n");
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
	if(p==NULL)//链表为空的时候特判  
		return 0;
	Node*fast=p;
	Node*slow=p;
	while(fast->next!=NULL&&fast->next->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	/*如果有奇数个节点，那么slow就是中点。偶数个则是slow和下一个*/
	if(fast->next!=NULL)//偶数个 
		printf("链表中点的值为：%d	%d	\n\n",slow->score,slow->next->score);
	else
		printf("链表中点的值为：%d	\n\n",slow->score);
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
	printf("\n------功能表------\n");
	printf("1、创建链表(新链表会覆盖旧链表哦)\n");
	printf("2、查找节点\n");
	printf("3、修改节点\n");
	printf("4、插入节点\n");
	printf("5、删除节点\n");
	printf("6、清空链表\n");
	printf("7、打印链表\n");
	printf("8、查找链表中点\n"); 
	printf("9、反转奇偶位置的节点\n"); 
	printf("输入0以退出程序\n------------------\n");
	printf("请输入要使用的功能(数字):");
	int num;
	scanf("%d",&num);
	return num;
}

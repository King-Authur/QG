#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct StackNode	//链表节点 
{
	ElemType data;
	struct StackNode *next;
}StackNode,*LinkStackPtr;	//指向链表节点的指针 

typedef struct LinkStack	//栈顶指针，头指针 
{
	LinkStackPtr top;
	int	count;
}LinkStack;

//链栈
Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s);//检测栈长度
Status pushLStack(LinkStack *s,ElemType data);//入栈
Status popLStack(LinkStack *s);//出栈
int menu(LinkStack *s);

#endif // STACK_H_INCLUDED

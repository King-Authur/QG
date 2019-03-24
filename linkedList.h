/***************************************************************************************
 *	File Name				:	linkedList.h 
 *	SYSTEM					:   win10
 *	Create Data				:	2019.3.23
 *	Author/Corportation		:	Authur 
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/
 
 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define struct of linked list
typedef struct node
{
 	int score;
 	struct node*next;
}Node;
/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Node *CreatList();
 *	@description : Creat a list until enter zero
 *	@param		 : None
 *	@return		 : None
 *  @notice      : None
 */
Node *CreatList();

/**
 *  @name        : Node* destory(Node* p);
 *	@description : destroy the list, free all the nodes
 *	@param		 : p(the head pointer)
 *	@return		 : None
 *  @notice      : None
 */
Node* destory(Node* p);

/**
 *  @name        : Node* insert(Node*head);
 *	@description : insert node q in the end of the list
 *	@param		 : p(head pointer)
 *	@return		 : None
 *  @notice      : None
 */
Node* insert(Node*head);

/**
 *  @name        : Node* delet(Node*p);
 *	@description : delete the node in the position as user requestion
 *	@param		 : p(head pointer)
 *	@return		 : None
 *  @notice      : None
 */
Node* delet(Node*p);

/**
 *  @name        : void alter(Node*p);
 *	@description : change the node 
 *	@param		 : p(head pointer)
 *	@return		 : None
 *  @notice      : None
 */
void alter(Node*p);

/**
 *  @name        : void output(Node*p);
 *	@description : out put all factors in the list
 *	@param		 : p(the head pointer)
 *	@return		 : None
 *  @notice      : None
 */
void output(Node*p);

/**
 *  @name        : void search(Node*p);
 *	@description : search the node in the list and response it is exit or not
 *	@param		 : p(the head pointer)
 *	@return		 : None
 *  @notice      : None
 */
void search(Node*p);

/**
 *  @name        : Node* reversal(Node *head);
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : p(the head pointer)
 *	@return		 : (the new head pointer)
 *  @notice      : choose to finish 
 */
Node* reversal(Node *head);

/**
 *  @name        : int search_middle(Node*p);
 *	@description : find the middle node in the linked list,and show the middle node's data
 *	@param		 : p(the head pointer)
 *	@return		 : zero or not
 *  @notice      : choose to finish 
 */
int search_middle(Node*p);

/**
 *  @name        : int menu();
 *	@description : present the functions of the program  
 *	@param		 : None
 *	@return		 : user's choose
 *  @notice      : None
 */ 
 int menu();

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif 

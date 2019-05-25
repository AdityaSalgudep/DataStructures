
#include "pch.h"
#include <stdio.h>
#include<malloc.h>
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;


void Push(PPNODE, int);
void Pop(PPNODE);
void Peek(PPNODE);
void Display(PNODE);
struct node
{
	int data;
	struct node *next;
};
int main()
{
	 
	PNODE first = NULL;
	PNODE last = NULL;
	int ch;
	do {
		printf("Enter Choice:\n  1.Push to Stack\n  2.Pop from Stack: \n  3.Peek Element 4.Display Stack: \n  4.Exit\n");
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1:printf("Enter Value:");
			int data, pos;
			scanf_s("%d", &data);
			printf("Enter Position:");
			scanf_s("%d", &pos);
			Push(&first, data);
			break;

		case 2:printf("Enter Position:");
			scanf_s("%d", &pos);
			
			Pop(&first);
			break;
		case 3:Peek(&first);
			break;
		case 4:Display(first);
			break;
		

		}

	} while (ch != 5);


}

void Push(PPNODE head, int value)
{
	PNODE newnode = (PNODE)malloc(sizeof(NODE));
	newnode->data = value;
	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		newnode->next = *head;
		*head = newnode;
	}
}

void Pop(PPNODE head)
{
	if (*head == NULL)
	{
		return;
	}

	else
	{
		PNODE temp;
		temp = *head;
		*head = (*head)->next;
		free(temp);

	}


}

void Peek(PPNODE head)
{
	if (* head == NULL)
	{
		printf("Stack is Empty");
	}

	else
	{
		printf("| %d |",(*head)->data);
	}

}

void Display(PNODE head)
{

	while (head != NULL)
	{
		printf("| %d |\n", head->data);
		head = head->next;
	}

}
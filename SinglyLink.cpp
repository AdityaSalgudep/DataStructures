
#include "pch.h"
#include <stdio.h>
#include<malloc.h>
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

int CountNode(PNODE);
void InsertFirst(PPNODE, int);
void InsertLast(PPNODE, int);
void InsertPosition(PPNODE first, int value, int pos);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void DeletePosition(PPNODE first, int pos);



void Display(PNODE);
struct node
{
	int data;
	struct node *next;
};

int main()
{
	PNODE first = NULL;
	printf("\nInsert First:-");
	InsertFirst(&first,10);
	Display(first);
	printf("\nInsert First:-");
	InsertFirst(&first, 20);
	Display(first);
	printf("\nInsert First:-");
	InsertFirst(&first, 30);
	Display(first);
	printf("\nInsert Last:-");
	InsertLast(&first, 40);
	Display(first);
	int cnt = CountNode(first);
	printf("\n Node Count =%d", cnt);
	printf("\nInsert Atposition 3:-");
	InsertPosition(&first, 50, 3);
	Display(first);
	printf("\nDelete First:-");
	DeleteFirst(&first);
	Display(first);
	printf("\nDelete Last:-");
	DeleteLast(&first);
	Display(first);
	printf("\nDelete Position 2:-");
	DeletePosition(&first,2);
	Display(first);
}

void InsertFirst(PPNODE head, int value)
{
	PNODE newnode = (PNODE)malloc(sizeof(NODE));
	newnode->data = value;
	newnode->next = NULL;

	newnode->next = *head;
	*head = newnode;

}

void InsertLast(PPNODE head, int value)
{
	PNODE newnode = (PNODE)malloc(sizeof(NODE));
	newnode->data = value;
	newnode->next = NULL;
	PNODE temp = *head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
}
void InsertPosition(PPNODE head, int value, int pos)
{

	PNODE newnode = (PNODE)malloc(sizeof(NODE));
	newnode->data = value;
	newnode->next = NULL;
	
	PNODE temp = *head;
	int c = CountNode(temp);
	for (int i = 1; i <= pos - 2; i++)
	{
		temp = temp->next;
	}

	printf("\n Node Count =%d", c);

	newnode->next = temp->next;
	temp->next = newnode;
}


void DeleteFirst(PPNODE head)
{
	PNODE temp = *head;
	*head = (*head)->next;
	free(temp);
}
void DeleteLast(PPNODE head)
{
	PNODE temp = *head;

	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	PNODE temp1 = temp->next;
	temp->next = NULL;
	free(temp1);
}
void DeletePosition(PPNODE head, int pos)
{
	PNODE temp = *head;
	for (int i = 1; i <= pos - 2; i++)
	{
		temp = temp->next;
	}

	PNODE temp1 = temp->next;
	temp->next = temp->next->next;
	free(temp1);
}

int CountNode(PNODE head)
{
	int c = 0;
	while (head != NULL)
	{
		head = head->next;
		c++;
	}
	return c;
}

void Display(PNODE head)
{
	printf("\n");
	while (head != NULL)
	{
		printf("%d-", head->data);
		head = head->next;

	}

}
/*
PNODE InsertFirst(PNODE head, int value)
{
	PNODE newnode = (PNODE)malloc(sizeof(NODE));
	newnode->data = value;
	newnode->next = NULL;

	newnode->next = head;
	head = newnode;

	return head;
}
PNODE InsertLast(PNODE head, int value)
{
	PNODE newnode = (PNODE)malloc(sizeof(NODE));
	newnode->data = value;
	newnode->next = NULL;

	PNODE temp = NULL;

	temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;

	return head;
}
*/

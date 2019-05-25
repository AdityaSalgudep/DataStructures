
#include "pch.h"
#include <stdio.h>
#include<malloc.h>


typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE);
int NodeCount(PNODE);
void InsertFirst(PPNODE, int);
void InsertLast(PPNODE, int);
void InsertPosition(PPNODE, int, int);

void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void DeletePosition(PPNODE, int);



struct node
{
	int data;
	struct node *next;
	struct node *prev;
};


int main()
{
	PNODE first = NULL;

	int ch;
	do {
		printf("Enter Choice:\n  1.Add to list\n  2.Delete from list: \n  3.Display List: \n  4.Exit\n");
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1:printf("Enter Value:");
			int data, pos;
			scanf_s("%d", &data);
			printf("Enter Position:");
			scanf_s("%d", &pos);
			InsertPosition(&first, data, pos);
			break;

		case 2:printf("Enter Position:");
			scanf_s("%d", &pos);
			DeletePosition(&first, pos);
			break;
		case 3: Display(first);

		}

	} while (ch != 4);
}

int NodeCount(PNODE head)
{
	int c = 0;
	while (head != NULL)
	{
		c++;
		head = head->next;
	}
	return c;
}
void InsertFirst(PPNODE head, int value)
{
	PNODE newnode = (PNODE)malloc(sizeof(NODE));

	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (*head == NULL)

	{
		*head = newnode;
	}
	else
	{
		newnode->next = *head;
		(*head)->prev = newnode;
		*head = newnode;
	}
}
void InsertLast(PPNODE head, int val)
{
	PNODE temp = *head;

	while (temp->next != NULL)
		temp = temp->next;

	PNODE newnode = (PNODE)malloc(sizeof(NODE));

	newnode->data = val;
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->prev = temp;
	temp->next = newnode;
}

void InsertPosition(PPNODE head1, int value, int pos)
{
	int c = NodeCount(*head1);
	PNODE head = *head1;
	if (pos<1 || pos >c + 1)
		printf("\nInvalid Position\n");
	else
	{
		if (pos == 1)
			InsertFirst(head1, value);
		else if (pos == c + 1)
			InsertLast(head1, value);
		else
		{
			PNODE newnode = (PNODE)malloc(sizeof(NODE));

			newnode->data = value;
			newnode->next = NULL;
			newnode->prev = NULL;
			for (int i = 1; i <= pos - 2; i++)
			{
				head = head->next;
			}
			newnode->next = head->next;
			newnode->prev = head;
			head->next = newnode;
		}
	}
}
void DeleteFirst(PPNODE head)
{
	if(*head==NULL)
	{
		return;
	}
	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return;
	}
	PNODE temp = *head;
	*head = ((*head)->next);
	(*head)->prev = NULL;

	free(temp);

}

void DeleteLast(PPNODE head1)
{
	PNODE head = *head1;

	while (head->next->next != NULL)
	{
		head = head->next;
	}
	PNODE temp = head->next;
	head->next = NULL;

	free(temp);

}
void DeletePosition(PPNODE head1, int pos)
{
	int c = NodeCount(*head1);
	PNODE head = *head1;
	if (pos<1 || pos >c)
		printf("\nInvalid Position\n");
	else
	{
		if (pos == 1)
			DeleteFirst(head1);
		else if (pos == c)
			DeleteLast(head1);
		else
		{
			for (int i = 1; i <= pos - 2; i++)
			{
				head = head->next;
			}
			PNODE temp1 = head->next;
			head->next = head->next->next;
			head->next->next->prev = head;
			free(temp1);

		}
	}
}



void Display(PNODE head)
{
	
	printf("\nThe List Contains:-");
	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		printf("%d-", head->data);
		head = head->next;
	}
	printf("\n\n");
}

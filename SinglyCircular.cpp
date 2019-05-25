
#include "pch.h"
#include <stdio.h>
#include<malloc.h>


typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE,PNODE);
int NodeCount(PNODE,PNODE);
void InsertFirst(PPNODE,PPNODE, int);
void InsertLast(PPNODE,PPNODE, int);
void InsertPosition(PPNODE,PPNODE, int, int);

void DeleteFirst(PPNODE,PPNODE);
void DeleteLast(PPNODE,PPNODE);
void DeletePosition(PPNODE,PPNODE, int);



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
		printf("Enter Choice:\n  1.Add to list\n  2.Delete from list: \n  3.Display List: \n  4.Exit\n");
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1:printf("Enter Value:");
			int data, pos;
			scanf_s("%d", &data);
			printf("Enter Position:");
			scanf_s("%d", &pos);
			InsertPosition(&first,&last, data, pos);
			break;

		case 2:printf("Enter Position:");
			scanf_s("%d", &pos);
			DeletePosition(&first,&last,pos);
			break;
		case 3: Display(first,last);

		}

	} while (ch != 4);

	
}

int NodeCount(PNODE head,PNODE tail)
{
	int cnt=0;
	if (head == NULL)
		return 0;
	
	do{
		head = head->next;
		cnt++;
	}while (head != tail->next);

	printf("%d", cnt);
	return cnt;
}
void InsertFirst(PPNODE head, PPNODE tail, int value)
{
	PNODE newnode = (PNODE)malloc(sizeof(NODE));
	newnode->data = value;
	newnode->next = NULL;
	
	if ((*head == NULL) && (*tail==NULL))
	{
		*head = newnode;
		*tail = newnode;
		(*tail)->next = *head;
	}
	else
	{
		newnode->next = *head;
		*head = newnode;
		(*tail)->next = *head;
	} 
}

void InsertLast(PPNODE head,PPNODE tail, int value)
{
	PNODE newnode = (PNODE)malloc(sizeof(NODE));
	newnode->data = value;
	newnode->next = *head;
	(*tail)->next = newnode;
	*tail = (*tail)->next;

}

void InsertPosition(PPNODE head1, PPNODE head2, int value, int pos)
{
	int c = NodeCount(*head1, *head2);
	printf("cnt is %d", c);
	if (pos == 1)
		InsertFirst(head1,head2, value);
	
	else if (pos == c + 1)
		InsertLast(head1, head2, value);

	else
	{
		PNODE newnode = (PNODE)malloc(sizeof(NODE));
		newnode->data = value;
		PNODE temp = *head1;
		for (int i = 1; i <= pos - 2; i++)
		{
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}

}

void DeleteFirst(PPNODE head,PPNODE tail)
{
	PNODE temp;
	temp = *head;
	*head = (*head)->next;
	(*tail)->next = *head;
	free(temp);
}

void DeleteLast(PPNODE head1,PPNODE tail)
{
	PNODE temp,temp1;
	temp = *tail;
	temp1 = *head1;
	while (temp1->next != *tail)
		temp1 = temp1->next;
	temp1->next = *head1;
	*tail = temp1;
	free(temp);
}

void DeletePosition(PPNODE head1,PPNODE tail, int pos)
{
	int c = NodeCount(*head1,*tail);
	if (pos == 1)
		DeleteFirst(head1, tail);
	else if (pos == c)
		DeleteLast(head1, tail);
	else
	{
		PNODE temp = *head1;
		for (int i = 1; i <= pos - 2; i++)
		{
			temp = temp->next;
		}
		PNODE temp1 = temp->next;
		temp->next = temp->next->next;
		free(temp1);
	}
}
void Display(PNODE head,PNODE last)
{
	do{
		printf("%d-", head->data);
		head = head->next;
	}while (head != last->next);
}
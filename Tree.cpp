
#include "pch.h"
#include <stdio.h>
#include<malloc.h>
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;


void PreOrder(PNODE);
void InOrder(PNODE);
void PostOrder(PNODE);
void InsertTree(PPNODE, int);

struct node
{
	int data;
	struct node *left;
	struct node *right;

};
int main()
{
	PNODE first=NULL;
	//InsertTree(&root, 10);
	//InsertTree(&root, 10);
	int ch;
	do {
		printf("Enter Choice:\n  1.Insert value into tree\n  2.Pree-Order: \n  3.In-Order 4.Post-Order \n  4.Exit\n");
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1:printf("Enter Value:");
			int data, pos;
			scanf_s("%d", &data);
			InsertTree(&first, data);
			break;

		case 2:PreOrder(first);
			break;
		case 3:InOrder(first);
			break;
		case 4:PostOrder(first);
			break;

		}

	} while (ch != 5);

}

void InsertTree(PPNODE root, int value)
{
	PNODE newnode = (PNODE)malloc(sizeof(NODE));
	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;
	PNODE temp = *root;
	if (*root == NULL)
		*root = newnode;
	else
	{
		while (1)
		{

			if (temp->data > value)
			{
				if (temp->left == NULL)
				{
					temp->left = newnode;
					break;
				}
				
				temp = temp->left;


			}
			else if (temp->data < value)
			{
				if (temp->right == NULL)
				{
					temp->right = newnode;
					break;
				}
				temp = temp->right;
			}
			else if (temp->data == newnode->data)
			{
				free(newnode);
				printf("Duplicates are not allowed");
				break;
			}
		}

	}

}

void PreOrder(PNODE root)
{
	if (root != NULL)
	{

		printf("%d-", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void PostOrder(PNODE root)
{
	if (root != NULL)
	{

		PreOrder(root->left);
		PreOrder(root->right);
		printf("%d-", root->data);
	}
}
void InOrder(PNODE root)
{
	if (root != NULL)
	{

		PreOrder(root->left);
		printf("%d-", root->data);
		PreOrder(root->right);
	}
}
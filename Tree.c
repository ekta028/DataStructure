//Tree program in C

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertNode(PPNODE Head,int iNo) 
{
	PNODE temp = *Head;
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->lchild = NULL;
	newn -> rchild = NULL;

	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(1)
		{
			if(iNo > temp -> data)  
			{
				if(temp->rchild == NULL)
				{
					temp->rchild = newn;
					break;
				}
				temp = temp -> rchild;
			}
			else if(iNo < temp -> data) 
			{
				if(temp->lchild == NULL)
				{
					temp->lchild = newn;
					break;
				}
				temp = temp -> lchild;
			}
			else if(iNo == temp-> data) 
			{
				printf("Duplicates elements\n");
				free(newn);
				break;
			}
		}
	}
}

void Inorder(PNODE Head)
{
	if(Head != NULL)
	{
		Inorder(Head -> lchild); 
		printf("%d\t",Head->data);
		Inorder(Head ->rchild); 
	}
}

void Postorder(PNODE Head) 
{
	if(Head != NULL)
	{
		Postorder(Head -> lchild); 
		Postorder(Head ->rchild); 
		printf("%d\t",Head ->data);
	}
}

void Preorder(PNODE Head) 
{
	if(Head != NULL)
	{
		printf("%d\t",Head ->data);
		Preorder(Head -> lchild); 
		Preorder(Head ->rchild); 
	}
}

void Count(PNODE Head,int *p)
{
	if(Head != NULL)
	{
		(*p)++;
		Count(Head->lchild,p);
		Count(Head->rchild,p);
	}
}

int main()
{
	PNODE Root = NULL;
	int iChoice = 1;
	int iRet  = 0,iNo = 0 , i = 0;

	while(iChoice != 0)
	{
		printf("Enter your choice\n");
		printf("1 : Insert node\n");
		printf("2 : Display Inorder\n");
		printf("3 : Display preorder \n");
		printf("4 : Display Postorder\n");
		printf("5 : Count nodes\n");
		printf("0 : Terminates the application\n");
		scanf("%d",&iChoice);

		switch(iChoice)
		{
			case 1 :
				printf("Insert node \n");
				scanf("%d",&iNo);
				InsertNode(&Root,iNo);
				break;

			case 2 :
				printf("Inoreder treavrsal\n");
				Inorder(Root);
				break;

			case 3 :
				printf("preoreder treavrsal\n");
				Preorder(Root);
				printf("\n");
				break;

			case 4 :
				printf("postoreder treavrsal\n");
				Postorder(Root);
				break;

			case 5 :
				i = 0;
				Count(Root,&i);
				printf("Number of nodes are : %d\n",i);
				i = 0;
				break;

			case 0 : 
				printf("Thanks you for using an application\n");
				break;

			default :
				printf("Enter the proper choice\n");
				break;
		}
	}
}


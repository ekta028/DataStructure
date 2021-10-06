//Write a program which displays all elements which are perfect from singly linear linked list.

//Output : 28 6


#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node
{
	int Data;
	struct node *Next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head,int no)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	newn->Next = NULL;
	newn->Data = no;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn->Next = *Head;
		*Head = newn;
	}
}

void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("|%d| -> ",Head->Data);
		Head = Head->Next;
	}
	printf("NULL\n\n");
}
		
int DisplayPerfect(PNODE Head)
{
	PNODE temp = Head;
	int iSum = 0, iCnt = 1;
	while(temp != NULL)
	{
		iSum = 0;
		
		for(iCnt = 1 ; iCnt <= temp->Data/2 ; iCnt++)
		{
			if(temp->Data  % iCnt == 0)
			{
				iSum = iSum + iCnt;
			}
		}
		if(iSum == temp->Data)
		{
			printf("%d\t",temp->Data);
		}
		temp = temp -> Next;
	}
}	

int main()
{
	PNODE First = NULL;
	
	InsertFirst(&First,45);
	InsertFirst(&First,80);
	InsertFirst(&First,6);
	InsertFirst(&First,11);
	InsertFirst(&First,28);
	
	Display(First);
	DisplayPerfect(First);
	
	return 0;
}
//Write a program which displays all elements which are prime from singly linear linked list.

//Output : 11 13 7


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
		
void DisplayPrime(PNODE Head)
{
	PNODE temp = Head;
	int iSum = 0, iCnt = 0 , flag = 1;
	
	while(temp != NULL)
	{
		flag = 1;
		
		for(iCnt = 2 ; iCnt <= temp->Data/2 ; iCnt++)
		{
			if(temp->Data % iCnt == 0)
			{
				flag = 0;
				break;
			}
		}
		if(flag == 1)
		{
			printf("%d\n",temp->Data);
		}
		temp = temp->Next;
	}
}	

int main()
{	
	PNODE First = NULL;
	
	InsertFirst(&First,7);
	InsertFirst(&First,13);
	InsertFirst(&First,6);
	InsertFirst(&First,11);
	InsertFirst(&First,28);
	
	Display(First);
	DisplayPrime(First);
	
	return 0;
}
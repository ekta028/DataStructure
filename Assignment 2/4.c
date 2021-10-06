//Write a program which display smallest digit from each elements from singly linear linked list.

//Output : 1 4 1 2 0


#include<stdio.h>
#include<stdlib.h>

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
	newn->Data = no;
	newn->Next = NULL;
	
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
	printf("NULL\n");
}

int MinDigit(PNODE Head)
{
	PNODE temp = Head;
	int iSum = 0 , iRem = 0 , iMin = 9;
	
	while(temp != NULL)
	{
		iMin = 9;
		while(temp->Data != 0)
		{
			iRem = temp->Data % 10;
			
			if(iRem < iMin)
			{
				iMin = iRem;
			}
			temp->Data = temp->Data / 10;
		}
		printf("%d\t ",iMin);
		temp = temp->Next;
	}
}
	
int main()
{
	PNODE First = NULL;
	int iRet = 0;
	
	InsertFirst(&First,101);
	InsertFirst(&First,289);
	InsertFirst(&First,461);
	InsertFirst(&First,547);
	InsertFirst(&First,192);
	
	Display(First);
	MinDigit(First);
	
	
	return 0;
}
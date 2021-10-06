//Write a program which display largest digit from each elements from singly linear linked list.

//Output : 9 7 6 9 1


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

int MaxDigit(PNODE Head)
{
	PNODE temp = Head;
	int iSum = 0 , iRem = 0 , iMax = 0;
	
	while(temp != NULL)
	{
		iMax = 0;
		while(temp->Data != 0)
		{
			iRem = temp->Data % 10;
			
			if(iRem > iMax)
			{
				iMax = iRem;
			}
			temp->Data = temp->Data / 10;
		}
		printf("%d\t ",iMax);
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
	MaxDigit(First);
	
	
	return 0;
}
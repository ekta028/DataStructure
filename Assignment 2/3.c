//Write a program which display product of all digits of all elements from singly linear linked list.(Don't consider 0)

//Output : 18 20 24 16 1


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

int DigitProduct(PNODE Head)
{
	PNODE temp = Head;
	int iMult = 1 , iRem = 0;
	
	while(temp != NULL)
	{
		iMult = 1;
		while(temp->Data != 0)
		{
			iRem = temp->Data % 10;
			
			if(iRem == 0)
			{
				iRem = 1;
			}
			
			iMult = iMult * iRem;
			temp->Data = temp->Data / 10;
		}
		printf("%d\t ",iMult);
		temp = temp->Next;
	}
}
	
int main()
{
	PNODE First = NULL;
	int iRet = 0;
	
	InsertFirst(&First,101);
	InsertFirst(&First,280);
	InsertFirst(&First,461);
	InsertFirst(&First,540);
	InsertFirst(&First,192);
	
	Display(First);
	DigitProduct(First);
	
	
	return 0;
}
//Write a program which returns addition of all even elements form singly linear linked list.

//Output : 90


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

int EvenSum(PNODE Head)
{
	PNODE temp = Head;
	int iSum = 0;
	
	while(temp != NULL)
	{
		if(temp->Data % 2 == 0)
		{
			iSum = iSum + temp->Data;
		}
		temp = temp->Next;
	}
	return iSum;
}
	
int main()
{
	PNODE First = NULL;
	int iRet = 0;
	
	InsertFirst(&First,11);
	InsertFirst(&First,28);
	InsertFirst(&First,41);
	InsertFirst(&First,50);
	InsertFirst(&First,12);
	
	Display(First);
	
	iRet = EvenSum(First);
	printf("Sum is : %d",iRet);
	
	return 0;
}
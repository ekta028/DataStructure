//Singly Linear Linked List in C


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

void InsertLast(PPNODE Head,int no)
{
	PNODE newn = NULL;
	PNODE Temp = *Head;
	
	newn = (PNODE)malloc(sizeof(NODE));
	newn->Data = no;
	newn->Next = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(Temp->Next != NULL)
		{
			Temp = Temp->Next;
		}
		Temp->Next = newn;
	}
}

void DeleteFirst(PPNODE Head)
{
	PNODE Temp = *Head;
	if(*Head == NULL)
	{
		return;
	}
	else
	if((*Head)->Next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		*Head = (*Head)->Next;
		free(Temp);
	}
}

void DeleteLast(PPNODE Head)
{
	PNODE Temp = *Head;
	
	if(*Head == NULL)
	{
		return;
	}
	else
	if((*Head)->Next == NULL)	
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		while(Temp->Next->Next != NULL)
		{
			Temp = Temp->Next;
		}
		free(Temp->Next);
		Temp->Next = NULL;
	}
}

void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("|%d| -> ",Head->Data);
		Head = Head->Next;
	}
	printf("NULL");

}

int Count(PNODE Head)
{
	int iCnt = 0;
	while(Head != NULL)
	{
		iCnt++;
		Head = Head->Next;
	}
	return iCnt;
}

void InsertAtPosition(PPNODE Head,int no,int iPos)
{
	int iSize = 0,i = 0;
	PNODE newn = NULL;
	PNODE Temp = *Head;
	
	iSize = Count(*Head);
	
	if((iPos < 1) || (iPos > iSize + 1))
	{
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(Head,no);
	}
	else
	if(iPos == iSize + 1)
	{
		InsertLast(Head,no);
	}
	else
	{
		newn = (PNODE)malloc(sizeof(NODE));
		newn->Data = no;
		newn->Next = NULL;
		
		for(i = 1 ; i < iPos-1 ; i++)
		{
			Temp = Temp -> Next;
		}
		newn->Next = Temp->Next;
		Temp->Next = newn;
	}
}

void DeleteAtPosition(PPNODE Head,int iPos)
{
	int iSize = 0,i = 0;
	PNODE Temp = *Head;
	PNODE Target = NULL;
	
	iSize = Count(*Head);
	
	if((iPos < 1) || (iPos > iSize))
	{
		return;
	}
	
	if(iPos == 1)
	{
		DeleteFirst(Head);
	}
	else
	if(iPos == iSize)
	{
		DeleteLast(Head);
	}
	else
	{
		for(i = 1 ; i < iPos-1 ; i++)
		{
			Temp = Temp -> Next;
		}
		Target = Temp->Next;
		Temp->Next = Target->Next;
		free(Target);
	}
}

int main()
{
	PNODE First = NULL;
	int iRet = 0 , iOption = 1 , iValue = 0 , iPos = 0;
	
	while(iOption != 0)
	{
		printf("\n_________________________________\n");
		printf("Enter your action on Linked List :\n");
		printf("1 : Insert node at first position :\n");
		printf("2 : Insert node at last position :\n");
		printf("3 : Insert node at given position :\n");
		printf("4 : Delete First node :\n");
		printf("5 : Delete last node :\n");
		printf("6 : Delete node at given position :\n");
		printf("7 : Display the contents of linked list :\n");
		printf("8 : Count number of node of linked list:\n");
		printf("0 : Exit the application :\n");
		scanf("%d",&iOption);
		printf("\n_________________________________\n");
	
	
		switch(iOption)
		{
			case 1 : printf("Enter data to insert :\n");
					 scanf("%d",&iValue);
					 InsertFirst(&First,iValue);
					 break;
					
			case 2 : printf("Enter data to insert :\n");
					 scanf("%d",&iValue);
					 InsertLast(&First,iValue);
					 break;
					 
			case 3 : printf("Enter data to insert :\n");
					 scanf("%d",&iValue);
					 printf("Enter position :\n");
					 scanf("%d",&iPos);
					 InsertAtPosition(&First,iValue,iPos);
					 break;
		
			case 4 : DeleteFirst(&First);
					 break;
					
			case 5 : DeleteLast(&First);
					 break;
					
			case 6 : printf("Enter position :\n");
					 scanf("%d",&iPos);
					 DeleteAtPosition(&First,iPos);
					 break;
					 
			case 7 : printf("Nodes of linked list are :\n");
					 Display(First);
					 break;
					
			case 8 : iRet = Count(First);
					 printf("Number of nodes are :%d\n",iRet);
					 break;
					
			case 0 : printf("Thank you for using linked list application\n");
					 break;
		
			default : printf("Please enter valid option");
					  break;
		}//End of switch
	}//End of while
	return 0;
}//End of main
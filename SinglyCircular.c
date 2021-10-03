//Singly Circular Link List in C	


#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head,PPNODE Tail,int iNo)
{
	PNODE newn = NULL;

	newn = (PNODE)malloc(sizeof(NODE));
    newn->next = NULL;
	newn->data = iNo;

	if((*Head == NULL) && (*Tail == NULL))
	{
		*Head = newn;
        *Tail = newn;
        (*Tail)->next = *Head;
	}
	else
	{
		newn->next = *Head;
		*Head = newn;
		(*Tail)->next = *Head;
	}
}

void InsertLast(PPNODE Head,PPNODE Tail,int iNo)
{
	PNODE newn = NULL;
	;

	newn = (PNODE)malloc(sizeof(NODE));
    newn->next = NULL;
	newn->data = iNo;

	if((*Head == NULL) && (*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
		(*Tail)->next = *Head;
	}
	else
	{
		(*Tail)->next = newn;
		*Tail = newn;
		(*Tail)->next = *Head;
	}
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	PNODE Temp = *Head;
	if((*Head == NULL) && (*Tail == NULL))
	{
		return;
	}
	else
	if((*Head)->next == *Tail)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		*Head = (*Head)->next;
		free(Temp);
		(*Tail)->next = *Head;
	}
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
	PNODE Temp = *Head;
	
	if((*Head == NULL) && (*Tail == NULL))
	{
		return;
	}
	else
	if((*Head)->next == *Tail)	
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		while(Temp->next->next != *Tail)
		{
			Temp = Temp->next;
		}
		free(Temp->next->next);
		*Tail = Temp->next;
		(*Tail)->next = *Head;
	}
}

void Display(PNODE Head,PNODE Tail)
{
	do
	{
		printf("|%d| -> ",Head->data);
		Head = Head -> next;
	}while(Head != Tail->next);
}

int CountNode(struct node *Head,struct node *Tail)
{
	int CountNode = 0;
	
	do
	{
		CountNode++;
		Head = Head->next;
	}while(Head != Tail->next);
	
	return CountNode;
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int no,int iPos)
{
	int iSize = 0,i = 0;
	PNODE newn = NULL;
	PNODE Temp = *Head;
	
	iSize = CountNode(*Head,*Tail);
	
	if((iPos < 1) || (iPos > iSize + 1))
	{
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(Head,Tail,no);
	}
	else
	if(iPos == iSize + 1)
	{
		InsertLast(Head,Tail,no);
	}
	else
	{
		newn = (PNODE)malloc(sizeof(NODE));
		newn->data = no;
		newn->next = NULL;
		
		for(i = 1 ; i < iPos-1 ; i++)
		{
			Temp = Temp -> next;
		}
		newn->next = Temp->next;
		Temp->next = newn;
	}
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int Pos)
{
	int i = 0;
	PNODE temp = NULL , target = NULL;
	
	if(Pos > (CountNode(*Head,*Tail)))
	{
		return;
	}
	else
	if(Pos == 1)
	{
		DeleteFirst(Head,Tail);
	}
	else
	if(Pos == (CountNode(*Head,*Tail)))
	{
		DeleteLast(Head,Tail);
	}
	else
	{
		temp = *Head;
		
		for(i = 1 ; i < Pos-1 ; i++)
		{
			temp = temp->next;
		}
		target = temp->next;
		temp->next = target->next;
		free(target);
	}
}

int main()
{
	PNODE First = NULL , Tail = NULL;
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
					 InsertFirst(&First,&Tail,iValue);
					 break;
					
			case 2 : printf("Enter data to insert :\n");
					 scanf("%d",&iValue);
					 InsertLast(&First,&Tail,iValue);
					 break;
					 
			case 3 : printf("Enter data to insert :\n");
					 scanf("%d",&iValue);
					 printf("Enter position :\n");
					 scanf("%d",&iPos);
					 InsertAtPos(&First,&Tail,iValue,iPos);
					 break;
		
			case 4 : DeleteFirst(&First,&Tail);
					 break;
					
			case 5 : DeleteLast(&First,&Tail);
					 break;
					
			case 6 : printf("Enter position :\n");
					 scanf("%d",&iPos);
					 DeleteAtPos(&First,&Tail,iPos);
					 break;
					 
			case 7 : printf("Nodes of linked list are :\n");
					 Display(First,Tail);
					 break;
					
			case 8 : iRet = CountNode(First,Tail);
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
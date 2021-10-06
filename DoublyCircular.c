//Doubly Circular Linked List in C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int data;
	struct node *next,*prev;
}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
	PNODE newn = NULL;

	newn = (PNODE)malloc(sizeof(NODE));
	newn->next = NULL;
	newn->prev = NULL;
	newn->data = no;

	if((*Head == NULL) && (*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
		(*Tail)->next = *Head;
		(*Head)->prev = *Tail;
	}
	else
	{
		newn->next = *Head;
		(*Head)->prev = newn;
		*Head = newn;
		(*Tail)->next = *Head;
		(*Head)->prev = *Tail;
	}
}

void InsertLast(PPNODE Head,PPNODE Tail,int No)
{
	PNODE newn = NULL;
	PNODE temp = *Head;

	newn = (PNODE)malloc(sizeof(NODE));
	newn->next = NULL;
	newn->prev = NULL;
	newn->data = No;
	
	if(*Head == NULL && *Tail == NULL)
	{
		*Head = newn;
		*Tail = newn;
		(*Head)->prev = *Tail;
		(*Tail)->next = *Head;
	}
	else
	{
		(*Tail)->next = newn;
		newn->prev = (*Tail);
		*Tail = newn;
		(*Head)->prev = *Tail;
		(*Tail)->next = *Head;
	}
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	PNODE temp = *Head;

	if(*Head == NULL && *Tail == NULL)
	{
		
	}
	else
	if(*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		*Head = (*Head)->next;
		(*Tail)->next = *Head;
		(*Head)->prev = *Tail;
		free(temp);
	}
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
	PNODE temp = *Tail;
	
	if((*Head == NULL) && (*Tail == NULL))
	{
		
	}
	else
	if(*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		*Tail = (*Tail)->prev;
		(*Tail)->next = *Head;
		(*Head)->prev = *Tail;
		free(temp);
	}
}

int Count(PNODE Head,PNODE Tail)
{
	int Count = 0;
	do
	{
		Count++;
		Head = Head->next;
	}while(Head != Tail->next);
	
	return Count;
}

void Display(PNODE Head,PNODE Tail)
{
	do
	{
		printf("|%d| -> ",Head->data);
		Head = Head->next;
	}while(Head != Tail->next);
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int no,int iPos)
{
	int iSize = 0,i = 0;
	PNODE newn = NULL;
	PNODE temp = *Head;
	
	iSize = Count(*Head,*Tail);
	
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
			temp = temp -> next;
		}
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
	}
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int Pos)
{
	int i = 1;
	PNODE temp = *Head;
	PNODE t = temp;
	
	if(Pos >(Count(*Head,*Tail)))
	{
		
	}
	else
	if(Pos == 1)
	{
		DeleteFirst(Head,Tail);
	}
	else
	if(Pos == (Count(*Head,*Tail)))
	{
		DeleteLast(Head,Tail);
	}
	else
	{
		while(i < Pos-1)
		{
			temp = temp->next;
			i++;
		}
		t = temp->next;
		temp->next = t->next;
		t->next->prev = temp;
		free(t);
	}
}

int main()
{
	PNODE First = NULL , Tail = NULL;
	int iOption = 1 , iValue = 0 , iRet = 0 , iPos = 1;
	
	
	while(iOption != 0)
	{
		printf("\n______________________________\n");
		printf("Please select the option:\n");
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
					
			case 8 : iRet = Count(First,Tail);
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

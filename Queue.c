//Queue Implementation in C


#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	int data;
	struct node *Next;
}NODE,*PNODE,**PPNODE;

void Enqueue(PPNODE Head,int no)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = no;
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

int Dequeue(PPNODE Head)
{
    int iRet = -1;
	PNODE Temp = *Head;
	
	if(*Head == NULL)
	{
		printf("Queue is Empty");
        return -1;
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
        iRet = Temp->Next->data;
		free(Temp->Next);
		Temp->Next = NULL;
	}
    return iRet;
}

void Display(PNODE Head)
{
	while(Head != NULL)
	{
        printf("|%d| -> ",Head->data);
		Head = Head->Next;
	}
    printf("\n");

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

int main()
{
	PNODE First = NULL;			
	int iOption = 1 ,iRet = 0,iNo = 0;
	
	while(iOption != 0)
	{
		printf("Please select the option\n");
		printf("1 : Add the element\n");
		printf("2 : Remove the element\n");
		printf("3 : Display the elements\n");
		printf("4 : Count number of elements\n");
		printf("0 : Exit the application\n");
		scanf("%d",&iOption);
        printf("\n_________________________________\n");
		
		switch(iOption)
		{
			case 1 :
				printf("Enter the element to Add\n");
				scanf("%d",&iNo);
				Enqueue(&First,iNo);
				break;
				
			case 2:
				iRet = Dequeue(&First);
				printf("Removed element is : %d\n",iRet);
				break;
			
			case 3:
				printf("Elemets of Queue are\n");
				Display(First);
				break;
				
			case 4:
				iRet = Count(First);
				printf("Number of elements in Queue are : %d\n",iRet);
				break;
				
			case 0:
				printf("Thank you for using Queue application\n");
				break;
				
			default:
				printf("Please Enter valid Number\n");
				break;
		}
	}
	return 0;
}

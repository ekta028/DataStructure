//Stack Implementation in C


#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	int data;
	struct node *Next;
}NODE,*PNODE,**PPNODE;

void Push(PPNODE Head,int no)
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

int Pop(PPNODE Head)
{
    int iRet = -1;
    PNODE Temp = *Head;

	if(*Head == NULL)
	{
		printf("Stack is Empty\n");
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
        iRet = Temp->data;
		free(Temp);
	}
    return iRet;
}

void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("|%d| <- ",Head->data);
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

int Peek(PNODE Head)
{
    int iSize = Count(Head);

    if(iSize == 0)
    {
        printf("Stack is Empty");
        return -1;
    }
    else
    {
        return Head->data;
    }
}

int main()
{
	PNODE First = NULL;			
	int iOption = 1 ,iRet = 0,iNo = 0;
	
	while(iOption != 0)
	{
		printf("Please select the option\n");
		printf("1 : Push the element\n");
		printf("2 : Pop the element\n");
		printf("3 : Display the elements\n");
		printf("4 : Count number of elements\n");
		printf("5 : Peek element\n");
		printf("0 : Exit the application\n");
		scanf("%d",&iOption);
        printf("\n_________________________________\n");
		
		switch(iOption)
		{
			case 1 :
				printf("Enter the element to Push\n");
				scanf("%d",&iNo);
				Push(&First,iNo);
				break;
				
			case 2:
				iRet = Pop(&First);
				printf("Popped element is : %d\n",iRet);
				break;
			
			case 3:
				printf("Elemets of stack are\n");
				Display(First);
				break;
				
			case 4:
				iRet = Count(First);
				printf("Number of elements in stack are : %d\n",iRet);
				break;
				
			case 5:
				iRet = Peek(First);
				printf("Value of top element is : %d\n",iRet);
				break;
				
			case 0:
				printf("Thank you for using Stack application\n");
				break;
				
			default:
				printf("Please Enter valid Number\n");
				break;
		}
	}
	return 0;
}

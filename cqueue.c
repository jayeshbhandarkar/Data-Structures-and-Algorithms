#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int cqueue_arr[MAX];
int front = -1;
int rear = -1;
void display();
void insert(int item);
int delete();
int isEmpty();
int isFull();

void main()
{
	int choice, item;
	while(1)
	{
		printf("\n 1. Insert");
		printf("\n 2. Delete");
		printf("\n 3. Display");
		printf("\n 4. Quit \n");
		printf("\n Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n Enter the elements for insertion: ");
				scanf("%d",&item);
				insert(item);
				break;
				
			case 2:
				printf("\n Element deleted is : %d",delete());
				break;
				
			case 3:
				display();
				break;
				
			case 4:
				exit(1);
				
			default :
				printf("\n Invalid Input"); 
		}		
	}	
}
void insert(int item)
{
	if(isFull())
	{
		printf("\n Queue Overflow \n");
		return;
	}
	if(front==-1)
	{
		front=0;
	}
	if(rear==MAX-1)
	{
		rear=0;
	}
	else 
	{
		rear=rear+1;
	}
	
	cqueue_arr[rear]=item;	
}

int delete()
{
	int item;
	if(isEmpty())
	{
		printf("\n Queue Underflow");
		exit(1);
	}
	item = cqueue_arr[front];
	if(front==rear)
	{
		front = -1;
		rear = -1;
	}
	else if(front==MAX-1)
	{
		front = 0;
	}
	else
	{
		front = front+1;
	}
	return item;
}

void display()
{
	int i;
	if(isEmpty())
	{
		printf("\n Queue is Empty");
		return;
	}
	printf("\n Queue elements : ");
	i = front;
	if(front<=rear)
	{
		while(i<=rear)
		{
			printf(" %d",cqueue_arr[i++]);
		}
	}
	else
	{
		while(i<=MAX-1)
		{
			printf(" %d",cqueue_arr[i++]);
		}
		i=0;
		while(i<=rear)
		{
			printf(" %d",cqueue_arr[i++]);
		}
	}
	printf("\n");
}

int isFull()
{
	if(front==0&&rear==MAX-1||front==rear+1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isEmpty()
{
	if(front==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


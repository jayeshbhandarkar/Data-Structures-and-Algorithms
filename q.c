#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue_arr[max];
int rear=-1;
int front=-1;
void insert(int item);
int del();
int isEmpty();
int isFull();
void display();
int main()
{
	int choice,item;
	while(1)
	{
		printf("\n 1.Insert\n");
		printf("\n 2.Delete\n");
		printf("\n 3.Display all element\n");
		printf("\n 4.Quit\n");
		printf("\n Enter your choice:   ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Input the element for adding in queue:     ");
				scanf("%d",&item);
				insert(item);
			break;
			case 2:
				item=del();
				printf("Deleted elements is %d",item);
			break;
			case 3:
				display();
			break;
			case 4:
				exit(1);
			break;
			default:
				printf("wrong choice \n");
		}
	}
}
void insert(int item)
{
	if(isFull())
	{
		printf("Queue overflow \n");
		return;
	}
	if(front==-1)
	{
		front=0;
	}
	
	rear=rear+1;
	queue_arr[rear]=item;	
}
int del()
{
	int item;
	if(isEmpty())
	{
		printf("Queue underflow \n");
		exit(1);
	}
	item=queue_arr[front];
	front=front+1;
	return item;
}
int isEmpty()
{
	if(front==-1||front==rear+1)
		return 1;
	else
		return 0;
}
int isFull()
{
	if(rear==max-1)
		return 1;
	else
		return 0;
}
void display()
{
	int i;
	if(isEmpty())
	{
		printf("Queue is empty\n");	
		return;
	}
	printf("Queue is:");
	for(i=front;i<=rear;i++)
	{
		printf("%d",queue_arr[i]);
		printf("\n\n");
	}
}

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push (int items);
int pop();
int isempty();
int isfull();
void display();
int main()
{
	int choice,item;
	while(1)
	{
		printf("\n MENU ");
		printf("\n1.PUSH");
		printf("\n2.POP");
		printf("\n3.DISPLAY");
		printf("\n4.QUIT");
		printf("\n\n Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n Enter the items to be Pushed :\t");
				scanf("%d",&item);
				push(item);
			break;
			case 2:
				item=pop();
				printf("\n Poped element is :%d ",item);
			break;
			case 3:
				display();
			break;
			case 4:
				exit(0);
			default:

				printf("\n Wrong choice");
		}
	}
}
void push (int item)
{
	if(isfull())
	{
		printf("\n STACK IS FULL");
		return;
	}
	top=top+1;
	stack[top]=item;
}
int pop()
{
	int item;
	if(isempty())
	{
		printf("\n STACK IS EMPTY ");
		exit(1);
	}
	item=stack[top];
	top=top-1;
	return item;
}
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int  isfull()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}
void display()
{
	int i;
	if(isempty())
	{
		printf("\n STACK IS EMPTY ");
		return;
	}
	for(i=top;i>=0;i--)
	{
		printf("%d \n ",stack[i]);
	}
	printf("\n");
}

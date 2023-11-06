#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int info;
	struct node* next;
}*head;
void addbeg(int in)
{
	struct node *newNode;
	newNode = malloc(sizeof(struct node));
	newNode->info = in;
	newNode->next = head;
	head = newNode;
}
void addend(int in)
{
	struct node *newNode;
	newNode = malloc(sizeof(struct node));
	newNode->info = in;
	newNode->next = NULL;
	struct node *temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}
void display()
{
	struct node *temp = head;
	printf("\nList elements are :");
	while(temp != NULL)
	{
		printf(" %d ",temp->info);
		temp = temp->next;
	}
	printf("\n");
}
void main()
{
	head = NULL;
	int ch, data;
	while(1)
	{
		printf("\n \t MENU \n");
		printf("\n 1. Add at Begining");
		printf("\n 2. Add at End");
		printf("\n 3. Display List");
		printf("\n 4. Exit \n");
		printf("\n Enter your Choice : ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
				printf("\n Enter Element : ");
				scanf("%d", &data);
				addbeg(data);
				
				break;
			case 2:
				printf("\n Enter Element : ");
				scanf("%d", &data);
				addend(data);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default :
				printf("Invalid Input...");
		}
	}
}

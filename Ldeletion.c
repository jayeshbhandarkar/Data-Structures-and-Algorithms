#include<stdio.h>
#include<malloc.h>
struct node
{
	int info;
	struct node *link;
}*start;

void createlist(int data)
{
	struct node *q, *tmp;
	tmp = malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link==NULL;
	if(start==NULL)
	{
		start=tmp;
	}	
	else
	{
		q=start;
		while(q->link!=NULL)
			q=q->link;
		q->link=tmp;
	}
}

void display()
{
	struct node *q;
	if(start==NULL)
	{
		printf("\n List is Empty");
	}
	else
	{
		q=start;
		printf("\n List is = ");
		while(q!=NULL)
		{
			printf("%d ", q->info);
			q=q->link;
		}
		printf("\n");
	}
}

void add(int data)
{
	struct node *tmp, *q;
	tmp = malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("\n Unable to Allocate Memory");
	}
	else
	{
		tmp->info=data;
		tmp->link=NULL;
		while(q!=NULL && q->link!=NULL)
			q=q->link;
		q->link=tmp;
		printf("\n Data Inserted Successfully");
	}
}

int del(int data)
{
	struct node *tmp, *q;
	if(start->info==data)
	{
		tmp = start;
		start=start->link;
		free(tmp);
		return 0;
	}
	q=start;
	while(q->link->link!=NULL)
	{
		if(q->link->info==data)
		{
			tmp=q->link;
			q->link=tmp->link;
			free(tmp);
			return 0;
		}
		q=q->link;
	}
	if(q->link->info==data)
	{
		tmp=q->link;
		free(tmp);
		q->link=NULL;
		return 0;
	}
	printf("\n Element %d not found",data);
	return 0;
}
intmain()
{
	int choice, n, m, position, i;
	while(1)
	{
		printf("\n 1. Create List");
		printf("\n 2. Display");
		printf("\n 3. Add at End");
		printf("\n 4. Delete");
		printf("\n 5. Quit");
		printf("\n Enter the choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				start = NULL;
				printf("How Many Nodes you want: ");
				scanf("%d",&n);
				
				for(i=0; i<n; i++)
				{
					printf("\n Enter the elements: ");
					scanf("%d", &m);
					createlist(m);
				}
				break;
			
			case 2:
				display();
				break;
				
			case 3:
				printf("\n Enter the element: ");
				scanf("%d",&m);
				add(m);
				break;
				
			case 4: 
				if(start==NULL)
				{
					printf("\n List is Empty");
					continue;
				}
				printf("\n Enter the element for deletion :");
				scanf("%d",&m);
				del(m);
				break;
				
			case 5:
				return 0;
				
			default:
				printf("\n Wrong Choice");
		}
	}
}

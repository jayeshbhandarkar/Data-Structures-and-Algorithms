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

void search(int key)
{
	int count=0,flag=0;
	struct node *temp = start;
	while(temp != NULL)
	{
		count++;
		if(key==temp->info)
		{
			printf("\n %d Element is found at position %d ",key,count);
			flag=1;
		}
		temp = temp->link;		
	}
	if(flag==0)
	{
		printf("\n Element is not found...");
	}
}

intmain()
{
	int choice, n, m, position, i,key;
	while(1)
	{
		printf("\n 1. Create List");
		printf("\n 2. Display");
		printf("\n 3. Search");
		printf("\n 4. Quit");
		printf("\n Enter the choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				start = NULL;
				printf("How Many Nodes you want: ");
				scanf("%d",&n);
				
				for(i=0;i<n;i++)
				{
					printf("\n Enter the elements: ");
					scanf("%d",&m);
					createlist(m);
				}
				break;
			
			case 2:
				display();
				break;
				
			case 3:
				printf("\n Enter Search Element : ");
				scanf("%d",&key);
				search(key);
				break;
				
			case 4: 
				return 0;
				
			default:
				printf("\n Wrong Choice");
		}
	}
}

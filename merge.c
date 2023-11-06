#include<stdio.h>
#define MAX 20

void merge(int a1[], int a2[], int a3[], int n1, int n2);
void main()
{
	int a1[MAX], a2[MAX], a3[2*MAX], n1, n2, i;
	
	printf("\n Enter the number of elements for Array a1: ");
	scanf("%d",&n1);
	printf("\n Enter the elements in sorted form");
	
	for(i=0;i<n1;i++)
	{
		printf("\n Elements are %d : ",i+1);
		scanf("%d",&a1[i]);
	}
	
	printf("\n Enter the number of elements of Array a2: ");
	scanf("%d",&n2);
	printf("\n Enter the elements in sorted form");
	
	for(i=0;i<n2;i++)
	{
		printf("\n Elements are %d : ",i+1);
		scanf("%d",&a2[i]);
	}	
	
	merge(a1,a2,a3,n1,n2);
	printf("\n Merge List : ");
	for(i=0;i<n1+n2;i++)
	{
		printf(" %d",a3[i]);
	}
	printf("\n");
}

void merge(int a1[], int a2[], int a3[], int n1, int n2)
{
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	
	while((i<=n1-1) && (j<=n2-1))
	{
		if(a1[i]<a2[j])
		{
			a3[k++] = a1[i++];
		}
		else
		{
			a3[k++] = a2[j++];
		}
	}
	
	while(i<=n1-1)
	{
		a3[k++] = a1[i++];
	}
	
	while(j<=n2-1)
	{
		a3[k++] = a2[j++];
	}
}

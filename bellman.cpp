Name: Kalparatna

#include<iostream>
using namespace std;
#include<stdlib.h>
#define max 100
#define infinity 9999
#define nil -1
#define true 1
#define false 0
int n;
int adj[max][max];
int predecessor[max];
int pathlength[max];
int ispresent_in_queue[max];
int front,rear;
int queue[max];
void initialize_queue();
void insert_queue(int u);
int delete_queue();
int isempty_queue();
void create_graph();
void findpath(int s,int v);
int bellmanford(int s);
int main()
{
	int flag,s,v;
	create_graph();
	cout<<"enter source vertex";
	cin>>s;
	flag=bellmanford(s);
	if(flag==-1)
	{
		cout<<"error:negative cycle in graph";
		exit(1);
	}
	while(1)
	{
		cout<<"enter destination vertex (-1 to quit):";
		cin>>v;
		if(v==-1)
			break;
		if(v<0||v>=n)
			cout<<"this vertex does not exist";
		else if(v==s)
			cout<<"source and destination vertices are same\n";
		else if(pathlength[v]==infinity)
			cout<<"there is no path form source to destination vertex\n";
		else
			findpath(s,v);
	}
}

void findpath(int s,int v)
{
	int i,u;
	int path[max];	// stores the shortest path
	int shortdist=0;	// length of shortest path
	int count=0;	// number of vertices in the shortest path

	// stores the full path in the array path
	while(v!=s)
	{
		count++;
		path[count]=v;
		u=predecessor[v];
		shortdist += adj[u][v];
		v=u;
	}
	count++;
	path[count]=s;
	cout<<"shortest path is"<<endl;
	for(i=count;i>=1;i--)	
		cout<<path[i];
	cout<<"shortest distance is\n"<<shortdist;
} 

int bellmanford(int s)
{
	int k=0,i,current;   // k for negative weights
	for(i=0;i<n;i++)
	{
	predecessor[i]=nil;
	pathlength[i]=infinity;
	ispresent_in_queue[i]=false;

	}
	initialize_queue();
	//step 1
	pathlength[s]=0;	// make pathLength of source vertex 0
	insert_queue(s);	// insert the source vertex in the queue
	ispresent_in_queue[s]=true;
	while(!isempty_queue())
	{
		//step 2
		current=delete_queue();
		ispresent_in_queue[current]=false;
		if(s==current)
			k++;
		if(k>n)
			return -1;	// negative cycle reachable from source vertex
		//step 3
		for(i=0;i<n;i++)
		{
			if(adj[current][i]!=0)
				if(pathlength[i]>pathlength[current]+adj[current][i])
				{
					pathlength[i]=pathlength[current]+adj[current][i];
					predecessor[i]=current;
					if(!ispresent_in_queue[i])
					{
						insert_queue(i);
						ispresent_in_queue[i]=true;
					}
				}
		}
	}
	return 1;
}

void initialize_queue()
{
	int i;
	for(i=0;i<max;i++)
		queue[i]=0;
	rear=-1;
	front=-1;
}

int isempty_queue()
{
	if(front==-1|| front>rear)
		return 1;
	else 
		return 0;
}
void insert_queue(int added_item)
{
	if(rear==max-1)
	{
		cout<<"queue is empty";
		exit(1);
	}
	else
	{
		if(front==-1)	// if queue is initially empty
			front=0;
		rear=rear+1;
		queue[rear]=added_item;
	}
}

int delete_queue()
{
	int d;
	if(front==-1||front>rear)
	{
		cout<<"queue is empty\n";
		exit(1);
	}
	else
	{
		d=queue[front];
		front=front+1;
	}
	return d;
}
void create_graph()
{
	int i,m_e,origin,destin,wt;
	cout<<"Enter the number of vertices :";
	cin>>n;
	m_e=n*(n-1);
	for(i=1;i<=m_e;i++)
	{
		cout<<"Enter edges (-1 -1 to quit ):"<<i<<" ";
		cin>>origin>>destin;
			
		if((origin== -1) && (destin==-1))
			break;
		cout<<"Enter weight for this edge :";
		cin>>wt;
		if(origin>=n || destin>=n || origin<0 || destin<0)
		{
			cout<<"Invalid edge! \n";
		}
		else
			adj[origin][destin]=wt;
	}
}
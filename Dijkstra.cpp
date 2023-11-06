#include<iostream>
using namespace std;
#define max 10
#define temp 0
#define perm 1
#define infinity 9999
#define nil -1

void findpath(int s,int v);
void dijkstra(int s);
int min_temp();
void create_graph();

int n;
int adj[max][max];
int predecessor[max];	// predecessor of each vertex in shortest path
int pathlength [max];
int status[max];

int main()
{
	int s,v;
	create_graph();
	cout<<"enter source vertex:";
	cin>>s;
	dijkstra(s);
	cout<<"enter the destination vertex:";
	while(1)
	{
		cin>>v;
		if(v==-1)
			break;
		if(v<0 || v>=n)
			cout<<"This vertex does not exist \n";
		else if(v==s)
			cout<<"Source and destination are same\n";
		else if (pathlength[v]==infinity)
			cout<<"there is no path from source to destination:";
		else
			findpath(s,v);
	}
}

void findpath(int s, int v)
{
	int i,u;
	int path[max];	//stores shortest path
	int sd=0;	//lenth of shortest path
	int count=0;	//no. of vertices in then shortest path

	// stores the full path in the array path
	while(v!=s)
	{
		count++;
		path[count]=v;
		u=predecessor[v];
		sd=sd+adj[u][v];
		v=u;
	}
	count++;
	path[count]=s;
	cout<<"shortest path is:\n";
	for(i=count;i>=1;i--)
		cout<<path[i];
	cout<<"\n shortest distance is:\n"<<sd;
}

void dijkstra(int s)
{
	int i,current;
	// Make all the vertices temporary
	for(i=0;i<n;i++)
	{
		predecessor[i]=nil;
		pathlength[i]=infinity;
		status[i]=temp;
	}

	// Make pathLength of source vertex equal to 0
	pathlength[s]=0;
	while(1)
	{
		// search for temporary vertex with minimum pathlenght and make it current vertex
		current=min_temp();
		if(current==nil)
			return;
		status[current]=perm;

		for(i=0;i<n;i++)
		{
			//check for adjacent temporary vertices
			if(adj[current][i]!=0 && status[i]==temp)
				if (pathlength[current]+adj[current][i]<pathlength[i])
				{
					predecessor[i]=current;		//relabel
					pathlength[i]=pathlength[current]+adj[current][i];
				}
		}
	}
}

// Returns the temporary vertex with minimum value of pathLength, returns nil if no temporary vertex left or all temporary vertices left
// have pathLength infinity
int min_temp()
{
	int i;
	int min=infinity;
	int k=nil;
	for(i=0;i<n;i++)
	{
		if(status[i]==temp && pathlength[i]<min)
		{
		min=pathlength[i];
		k=i;
		}
	}
	return k;
}

void create_graph()
{
	int i,m_e,origin,distin,wt;
	cout<<"enter the number of vertices:";
	cin>>n;
	m_e= n*(n-1);
	for(i=1;i<=m_e;i++)
	{
		cout<<"enter edges(-1 -1 to quit):"<<i;
		cin>>origin>>distin;

		if((origin==-1) && (distin==-1))
			break;
		cout<<"enter weight for this edge:";
		cin>>wt;
		if(origin>=n || distin>=n || origin<0 || distin<0)
		{
			cout<<"invalid edge!\n";
			i--;
		}
		else
			adj[origin][distin]=wt;
	}
}
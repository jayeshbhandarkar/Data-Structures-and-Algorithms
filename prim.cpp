#include<iostream>
using namespace std;
#define max 50
#define temp 0
#define perm 1
#define infinity 9999
#define nil -1

struct edge
{
	int u;
	int v;
};
int n;
int adj[max][max];
int predecessor[max];
int status[max];
int length[max];

void create_graph();
void maketree(int r, struct edge tree[max]);
int min_temp();

int main()
{
	int wt_tree = 0;
	int i;
	int root;
	struct edge tree[max];
	create_graph();
	cout<<"Enter the root vertex : ";
	cin>>root;
	maketree(root, tree);
	cout<<"Edges to be included in spanning tree are :"<<endl;
	for(i=1; i<=n-1; i++)
	{
		cout<<"->"<<tree[i].u;
		cout<<endl<<tree[i].v;
		wt_tree += adj[tree[i].u][tree[i].v];
	}
	cout<<"Weight of spanning tree is :"<<wt_tree<<endl;
}
void maketree(int r, struct edge tree[max])
{
	int current,i;
	int count=0;
	for(i=0;i<n;i++)
	{
		predecessor[i]=nil;
		length[i]=infinity;
		status[i]=temp;
	}
	length[r]=0;
	while(1)
	{
		current=min_temp();
		if(current== nil)
		{
			if(count==n-1)        
				return;
			else         
			{
				cout<<"Graph is not connected,No spanning tree possible !!!!\n"<<endl;
				exit(1);
			}
		}
		status[current]=perm;        
	
		if(current!=r)
		{
			count++;
			tree[count].u=predecessor[current];
			tree[count].v=current;
		}
		for(i=0;i<n;i++)
			if(adj[current][i]>0 && status[i]==temp)
				if(adj[current][i]<length[i])
				{
					predecessor[i]=current;
					length[i]=adj[current][i];
				}
	}
}
int min_temp()
{
	int i;
	int min=infinity;
	int k=-1;
	for(i=0;i<n;i++)
	{
		if(status[i]==temp && length[i]<min)
		{
			min=length[i];
			k=i;
		}
	}
	return k;
}
void create_graph()
{
    int i,m_e,origin,destin,wt;
    cout<<"Enter the number of vertices :";
    cin>>n;
    m_e=n*(n-1)/2;
    for(i=1;i<=m_e;i++)
    {
        cout<<"Enter edges (-1 -1 to quit ) "<<i<<": ";
        cin>>origin>>destin;
	
        if((origin== -1) && (destin==-1))
        	break;
        cout<<"Enter weight for this edge :";
        cin>>wt;
        if(origin>=n || destin>=n || origin<0 || destin<0)
        {
            cout<<"Invalid edge! \n";
			i--;
        }
        else
		{
            adj[origin][destin]=wt;
			adj[destin][origin]=wt;
    	}
	}
}
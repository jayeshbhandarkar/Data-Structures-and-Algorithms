#include<iostream>
using namespace std;
#define max 50
#define initial 1
#define visited 2
int n;
int adj[max][max];
int state[max];
void create_graph();
void df_traversal();
void dfs(int v);
int stack[max], top= -1;
void push(int v);
int pop();
int isEmpty_stack();

int main()
{
  create_graph();
  df_traversal();
}

void df_traversal()
{
  int v;
  for( int v=0; v<n; v++)
    state[v]=initial;
  cout<<"\n Enter the starting node for DFS: ";
  cin>>v;
  dfs(v);
}

void dfs(int v)
{
  int i;
  push(v);
  while(!isEmpty_stack())
  {
    v=pop();
    if(state[v]==initial)
    {
      cout<<v;
      state[v]=visited;
    }
    for(i=n-1; i>=0; i--)
    {
      if(adj[v][i]==1 && state[i]==initial)
        push(i);
    }
  }
}

void push(int v)
{
  if(top==(max-1))
  {
    cout<<"Stack Overflow \n";
    return;
  }
  top=top+1;
  stack[top]=v;
}

int pop()
{
  int v;
  if(top==-1)
  {
    cout<<"Stack Underflow"<<"\n";
    exit(1);
  }
  else
  {
    v = stack[top];
    top = top-1;
    return v;
  }
}

int isEmpty_stack()
{
  if(top==-1)
    return 1;
  else
    return 0;
}

void create_graph()
{
  int i, max_edges, origin, destin;
  cout<<"Enter the No of Nodes: ";
  cin>>n;
  max_edges = n*(n-1);
  for(int i=1; i<=max_edges; i++)
  {
    cout<<"Enter Edge "<<i<<"Origin and Destination: ";
    cin>>origin>>destin;
    if((origin==-1) && (destin==-1))
        break;
    if(origin>=n||destin>=n||origin<0||destin<0)
    {
      cout<<"Invalid Edge !";
      i--;
    }
    else
      adj[origin][destin]=1;
  }
}
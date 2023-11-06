#include<iostream>
using namespace std;
#define max 50
#define initial 1
#define waiting 2
#define visited 3
int n;
int adj[max][max];
int state[max];
void create_graph();
void bf_traversal();
void bfs(int v);
int queue[max], front= -1, rear= -1;
void insert_queue(int  vertex);
int delete_queue();
int isEmpty_queue();

int main()
{
  create_graph();
  bf_traversal();
}

void bf_traversal()
{
  int v;
  for( int v=0; v<n; v++)
  state[v]=initial;
  cout<<"Enter the starting vertex for BFS: "<<"\n";
  cin>>v;
  bfs(v);
}

void bfs(int v)
{
  int i;
  insert_queue(v);
  state[v]=waiting;
  while(!isEmpty_queue())
  {
    v=delete_queue();
    cout<<v<<" ";
    state[v]=visited;

    for(i=0;i<n;i++)
    {
      // Check for adjacent unvisited vertices
      if(adj[v][i]==1 && state[i]==initial)
      {
        insert_queue(i);
        state[i]=waiting;
      }
    }
  }
  cout<<endl;
}

void insert_queue(int vertex)
{
  if(rear==max-1)
    cout<<"Queue Overflow"<<"\n";
  else
  {
    if(front==-1) // if queue is empty
      front=0;
    rear=rear+1;
    queue[rear]=vertex;
  }
}

int isEmpty_queue()
{
  if((front==-1)||(front>rear))
    return 1;
  else
    return 0;
}

int delete_queue()
{
  int del_item;
  if(front==-1 || front>rear)
  {
    cout<<"Queue Underflow"<<"\n";
    exit(1);
  }
  del_item=queue[front];
  front=front+1;
  return del_item;
}

void create_graph()
{
  int org,dest;
  int i;
  cout<<"Enter the No of Vertices: ";
  cin>>n;
  int max_edges=n*(n-1);
  for(int i=1;i<max_edges;i++)
  {
    cout<<"Edge "<<i<<"Ori and Dest: ";
    cin>>org>>dest;
    if(org== -1||dest>=n||org<0||dest<0)
    {
      cout<<"Invalid !";
      i--;
    }
    else
      adj[org][dest]=1;
  }
}
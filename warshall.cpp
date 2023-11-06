#include<iostream>
using namespace std;

#define infinity 9999
#define max 100
int n;
int adj[max][max];
int D[max][max];
int pred[max][max];
void create_graph();
void floydwarshalls();
void findpath(int s, int d);
void display(int matrix[max][max], int n);

int main()
{
 int s,d;
 create_graph();
 floydwarshalls();
 while(1)
 {
  cout<<"Enter Source Vertex(-1 to exit) : ";
  cin>>s;
  if(s==-1)
  	break;
  cout<<"Enter Dest Vertex : ";
  cin>>d;
  if(s<0 || s>n-1 || d<0 || d>n-1)
  {
   cout<<"Enter Valid Vertices : \n\n";
   continue;
  }
  cout<<"Shortest Path is : "<<" ";
  findpath(s,d);
  cout<<"Length of this Path is : "<<D[s][d]<<"\n";
 }
}

void floydwarshalls()
{
 int i,j,k;
 for(i=0; i<n; i++)
  for(j=0; j<n; j++)
  { 
   if(adj[i][j]==0)
   {
    D[i][j]=infinity;
    pred[i][j]=-1;
   }
   else
   {
    D[i][j]=adj[i][j];
    pred[i][j]=i;
   }
  }
 for(k=0; k<n; k++)
  {
   for(i=0; i<n; i++)
    for(j=0; j<n; j++)
     if(D[i][k]+D[k][j]<D[i][j])
     {
      D[i][j]=D[i][k]+D[k][j];
      pred[i][j]=pred[k][j];
     }
   }
   cout<<"Shortest Path Matrix is : \n";
   display(D,n);
   cout<<"\nPredecessor Matrix is : \n";
   display(pred,n);
   for(i=0; i<n; i++)
    if(D[i][i]<0)
    {
     cout<<"Error: Negative Cycle\n";
     exit(1);
    }
}

void findpath(int s, int d)
{
 int i, path[max], count;
 if(D[s][d]==infinity)
 {
  cout<<"No Path \n";
  return;
 }
 count=-1;
 do
 {
  path[++count]=d;
  d=pred[s][d];
 }while(d!=s);

 path[++count]=s;
 for(i=count; i>=0; i--)
  cout<<path[i];
 cout<<"\n";
}

void display(int matrix[max][max], int n)
{
 int i,j;
 for(i=0; i<n; i++)
 {
  for(j=0; j<n; j++)
   cout<<matrix[i][j]<<" ";
  cout<<"\n";
 }
}

void create_graph()
{
 int i,max_edges, org, dest, wt;
 cout<<"Enter Number of Vertices: ";
 cin>>n;
 max_edges=n*(n-1);
 for(i=1; i<=max_edges; i++)
 {
  cout<<"Enter Edge (-1 -1 to quit)"<<i<<" : ";
  cin>>org>>dest;
  if((org==-1) && (dest==-1))
   break;
  cout<<"Enter Weight for this Edge: ";
  cin>>wt;
  if(org>=n || dest>=n || org<0 || dest<0)
  {
   cout<<"Invalid Edge!\n";
   i--;
  }
  else
   adj[org][dest]=wt;
 }
}  

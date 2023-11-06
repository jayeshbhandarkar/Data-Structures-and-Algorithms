#include<iostream>
using namespace std;
#define max 10
using namespace std;
int adj[max][max];
int main()
{
    int gt,n,m_e,src, dest;
    cout<<"Enter 1 for Undirected Graph or 2 for Directed Graph : ";
    cin>>gt;
    cout<<"Enter the No. of Vertices : ";
    cin>>n;
    if(gt==1)
        m_e=n*(n-1)/2;  // undirected graph
    else
        m_e=n*(n-1);    // directed graph
    for(int i=1;i<m_e;i++)
    {
        cout<<"Enter Edge"<<i<<" ";
        cin>>src>>dest;
        if(src>=n||dest>=n ||src<0||dest<0)
        {
            cout<<"Invalid Vertex !!"<<"\n";
            i--;
        }
        else
        {
            adj[src][dest]=1;
            if(gt==1)
                adj[dest][src]=1;
        }
    }
    cout<<"Adjanacy Matrix is : "<<"\n";
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            cout<<adj[i][j]<<"  ";
        }
    cout<<"\n";
    }
}
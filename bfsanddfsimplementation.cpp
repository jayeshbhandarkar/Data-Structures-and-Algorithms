#include <iostream>
#include <queue>
#include <stack>
#define n 8
using namespace std;
class Graph
{
    int adj[n + 1][n + 1];
    bool visited[n];

    public:
        void addedge(int u, int v, int op)
        {
            if (op == 1)
            {
                adj[u][v] = 1;
            }
            else
            {
                adj[u][v] = 1;
                adj[v][u] = 1;
            }
        }
        void bfs(int s)
        {
            visited[s] = true;
            queue<int> q;
            q.push(s);
            while (!q.empty())
            {
                int front = q.front();
                q.pop();
                cout << front << " ";
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (!visited[i] && adj[i][j] == 1)
                        {
                            q.push(i);
                            visited[i] = true;
                        }
                    }
                }
            }
        }
        void dfs(int s)
        {
            // dfs using recrusion
            visited[s] = true;
            cout << s << " ";
            for(int i = 0 ; i < n ; i++){
                if(adj[s][i] == 1 && visited[i] == false)
                {
                    dfs(i);
                }
            }
        }
};
int main()
{
    Graph g;
    int op;
    cout << "Which type of Graph you want ??" << endl;
    cout << "For Directed (enter 1)" << endl;
    cout << "For Undirected (enter 2)" << endl;
    cin >> op;
    g.addedge(0,1,op);
    g.addedge(0,2,op);
    g.addedge(0,3,op);
    g.addedge(0,4,op);
    g.addedge(1,5,op);
    g.addedge(2,5,op);
    g.addedge(3,6,op);
    g.addedge(4,6,op);
    g.addedge(5,7,op);
    g.addedge(6,7,op);
    g.bfs(0);
    // g.dfs(0); for dfs 
    return 0;
}
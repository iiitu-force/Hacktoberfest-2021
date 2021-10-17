#include <bits/stdc++.h>
using namespace std;

class Graph
{
    
    public:
        map<int, list<int>> l;
        map<int, bool> visited;

        void addEdge(int u, int v)
        {
            l[u].push_back(v);
            l[v].push_back(u);
        }

        bool dfs(int n, int par)
        {
            visited[n] = true;
            for(auto i : l[n])
            {
                if(!visited[i])
                {
                    bool cycle_mila = dfs(i, n);
                    if(cycle_mila)
                        return true;
                }
                else
                {
                    if(par != i)
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        void isCycle()
        {
            for(auto i : l)
            {
                if(!visited[i.first])
                {
                    if(dfs(i.first, -1))
                    {
                        cout << "YES";
                        return;
                    }
                }
            }
            cout << "NO";
        }
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(1, 2);
    g.isCycle();
}
 

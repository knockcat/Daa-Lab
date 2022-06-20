// CYCLE DETECTION IN UNDIRECTED GRAPH USING DFS

#include <iostream>
#include <vector>
using namespace std;

bool CheckForCycle(int i, int parent, vector<int> adj[], vector<bool> visited)
{
    visited[i] = true;
    for (auto itr : adj[i])
    {
        if (!visited[itr])
        {
            if (CheckForCycle(itr, i, adj, visited))
                return true;
            else if (itr != parent)
                return true;
        }
    }
    return false;
}

bool isCycle(int n, vector<int> adj[])
{
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            if (CheckForCycle(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cout << "Enter Number of Nodes & Edges : ";
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; ++i)
    {
        cout << "Enter Vertices : ";
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isCycle(n, adj))
        cout << "Input Graph Contains a Cycle ..." << endl;
    else
        cout << "Input Graph Doesn't Contains a Cycle ..." << endl;

    return 0;
}
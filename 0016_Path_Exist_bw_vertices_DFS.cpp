// Find if Path Exist Between two given Vetices Or Not using DFS

#include <iostream>
#include <vector>
using namespace std;

bool dfsOfGraph(int sv, int d, vector<bool> &visited, vector<int> adj[], vector<int> &dfs)
{
    dfs.push_back(sv);
    if (sv == d)
        return true;

    visited[sv] = true;

    for (auto itr : adj[sv])
    {
        if (!visited[itr])
            if (dfsOfGraph(itr, d, visited, adj, dfs))
                return true;
    }
    return false;
}

int main()
{
    int n, m;
    cout << "Enter Number of Nodes and Edges : ";
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, 0);
    vector<int> dfs;

    int s, d;
    cout << "Enter Source Vertex and Destination Vertex : ";
    cin >> s >> d;
    bool ans = false;

    if (dfsOfGraph(s, d, visited, adj, dfs))
    {
        for (auto i : dfs)
            cout << i << " ";
    }
    else
        cout << "No Path Exist";

    return 0;
}
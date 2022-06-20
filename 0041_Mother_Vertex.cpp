// Algorithm to Find Mother Vertex in a Graph.
// A mother Vertex is a vertex v such that there exists a path from v to all other vertices of the graph

#include <iostream>
#include <vector>
using namespace std;

void dfsOfGraph(int sv, vector<bool> &visited, vector<int> adj[])
{
    visited[sv] = true;

    for (auto itr : adj[sv])
    {
        if (!visited[itr])
            dfsOfGraph(itr, visited, adj);
    }
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
    }

    vector<bool> visited(n + 1, false);
    int ind = 0;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfsOfGraph(i, visited, adj);
            ind = i;
        }
    }

    fill(visited.begin(), visited.end(), false);
    dfsOfGraph(ind, visited, adj);

    for (int i = 0; i < visited[i]; ++i)
    {
        if (visited[i] == false)
        {
            cout << -1;
            return -1;
        }
    }

    cout << "Mother Vertex : " << ind << endl;

    return 0;
}
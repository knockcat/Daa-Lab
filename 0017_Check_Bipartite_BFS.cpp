// Check Graph is Bipartite Graph or not using BFS

// A graph that can be colored using 2 colors such that no two adjacent nodes have same color.
// Odd length cycle than graph is not bipatite.
// If it doesn't have a odd length cycle it is a bipatite grpah.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bipartiteBfs(int sv, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(sv);
    color[sv] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto itr : adj[curr])
        {
            if (color[itr] == -1)
            {
                color[itr] = 1 - color[curr];
                q.push(itr);
            }
            else if (color[itr] == color[curr])
                return false;
        }
    }
    return true;
}

bool CheckBipartite(vector<int> adj[], int n)
{
    vector<int> color(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (color[i] == -1)
        {
            if (!bipartiteBfs(i, adj, color))
                return false;
        }
    }
    return true;
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
        cout << "Enter Vertices of the Graph : ";
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (CheckBipartite(adj, n))
        cout << "Yes, the given Graph is Bipartite" << endl;
    else
        cout << "No, the given Graph is not Bipartite" << endl;

    return 0;
}
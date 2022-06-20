// Prim's Algorithm
// For Finding Minimum Spanning Tree

// we will check all the adjacent edges to a node
// we will pick the minimum weight edge
// then we will check the minimum edge from all the nodes
// taking in care that no cycle is formed

// BruteForce

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter Number of Vertices And Edges : ";
    cin >> n >> m;

    vector<pair<int, int>> adj[n];

    int u, v, wt;
    for (int i = 0; i < m; ++i)
    {
        cout << "Enter Vertices and weight : ";
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> parent(n, -1), key(n, INT_MAX), mstSet(n, 0);

    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    int ansWeight = 0;
    for (int count = 0; count < n - 1; count++)
    {

        int mini = INT_MAX, u;

        for (int v = 0; v < n; v++)
        {
            if (mstSet[v] == false && key[v] < mini)
                mini = key[v], u = v;
        }
        mstSet[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
                parent[v] = u, key[v] = weight;
        }
    }

    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " \n";
    return 0;
}

// Optimised Using priority queue we can get the minimum

/*
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter Number of Vertices And Edges : ";
    cin >> n >> m;

    vector<pair<int, int>> adj[n];

    int u, v, wt;
    for (int i = 0; i < m; ++i)
    {
        cout << "Enter Vertices and weight : ";
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> parent(n, -1), key(n, INT_MAX), mstSet(n, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;

    pq.push({0, 0});

    for (int count = 0; count < n - 1; ++count)
    {
        int curr = pq.top().second;
        pq.pop();

        mstSet[curr] = true;
        for (auto itr : adj[curr])
        {
            int v = itr.first;
            int weight = itr.second;

            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = curr;
                pq.push({key[v], v});
                key[v] = weight;
            }
        }
    }
    for (int i = 1; i < n; ++i)
        cout << parent[i] << " --- " << i << "\n";
    return 0;
}*/

/*
Enter Number of Vertices And Edges : 5 6
Enter Vertices and weight : 0 1 2
Enter Vertices and weight : 0 3 6
Enter Vertices and weight : 1 2 3
Enter Vertices and weight : 1 3 8
Enter Vertices and weight : 1 4 5
Enter Vertices and weight : 2 4 7
0 --- 1
1 --- 2
0 --- 3
1 --- 4
PS E:\DOCUMENTS\Daa-Lab>
*/
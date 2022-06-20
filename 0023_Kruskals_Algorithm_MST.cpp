// Kruskal's Algorithm
// Minimum Spaning Tree
// Disjoint Set DataStructure
// Take Edge if Do not belong to same Component

// TC = O(m(logm))
// SC = O(m)

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int find_set(int u, vector<int> &parent)
{
    if (parent[u] == u)
        return u;
    return find_set(parent[u], parent);
}

void union_set(int u, int v, vector<int> &parent)
{
    parent[u] = parent[v];
}

int main()
{
    int n, m;
    cout << "Enter Number of Vertices and Edges : ";
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> Graph;
    vector<pair<int, pair<int, int>>> mst;
    vector<int> parent(n);

    int u, v, wt;
    for (int i = 0; i < m; ++i)
    {
        cout << "Enter Vertices and weight : ";
        cin >> u >> v >> wt;
        Graph.push_back({wt, {u, v}});
    }

    for (int i = 0; i < n; ++i)
        parent[i] = i;

    sort(Graph.begin(), Graph.end());

    for (int i = 0; i < Graph.size(); ++i)
    {
        int v1 = find_set(Graph[i].second.first, parent);
        int u1 = find_set(Graph[i].second.second, parent);

        if (v1 != u1)
        {
            mst.push_back(Graph[i]);
            union_set(v1, u1, parent);
        }
    }

    for (int i = 0; i < mst.size(); ++i)
    {
        cout << mst[i].second.first << " " << mst[i].second.second << " weight -> " << mst[i].first << endl;
    }

    return 0;
}

/*
Enter Number of Vertices and Edges : 5 6
Enter Vertices and weight : 0 1 2
Enter Vertices and weight : 0 3 6
Enter Vertices and weight : 1 2 3
Enter Vertices and weight : 1 3 8
Enter Vertices and weight : 1 4 5
Enter Vertices and weight : 2 4 7
0 1 weight -> 2
1 2 weight -> 3
1 4 weight -> 5
0 3 weight -> 6
PS E:\DOCUMENTS\Daa-Lab>
*/
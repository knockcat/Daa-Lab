// Minimum Computation Cost of Merging files into a single file

// TC - O(nlogn(n))
// SC - O(n)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int MinComputation(vector<int> files)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < files.size(); ++i)
        pq.push(files[i]);

    int cost = 0;

    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        cost += a + b;

        pq.push(a + b);
    }
    return cost;
}

int main()
{
    // vector<int> files = {2, 3, 4, 5, 6, 7};
    vector<int> files = {5, 10, 20, 30, 30};
    // vector<int> files = {8, 8, 8, 8, 8};

    cout << "Minimum Computation :  " << MinComputation(files) << endl;

    return 0;
}

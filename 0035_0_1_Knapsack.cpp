// 0-1 knapsack

// recursive code

/*#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int w, int n)
{
    if (w == 0 || n == 0)
        return 0;

    if (wt[n - 1] <= w)
    {
        return max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
    }
    else
        return knapsack(wt, val, w, n - 1);
}

int main()
{
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int w = 50;

    int n = val.size();

    cout << knapsack(wt, val, w, n);

    return 0;
}*/

// memoised version (top-down)

/*#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// int t[100][1000];
vector<vector<int>> t(100, vector<int>(1000, -1));

int knapsack(vector<int> wt, vector<int> val, int w, int n)
{
    if (w == 0 || n == 0)
        return 0;

    if (t[n][w] != -1)
        return t[n][w];

    if (wt[n - 1] <= w)
    {
        return t[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
    }
    else
        return t[n][w] = knapsack(wt, val, w, n - 1);
}

int main()
{
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int w = 50;

    // memset(t, -1, (sizeof(t)));

    int n = val.size();

    cout << knapsack(wt, val, w, n);

    return 0;
}*/

// dp bottom-up approach

#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int w, int n)
{
    vector<vector<int>> t(n + 1, vector<int>(w + 1, -1));

    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < w + 1; ++j)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < w + 1; ++j)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][w];
}

int main()
{
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int w = 50;

    int n = val.size();

    cout << knapsack(wt, val, w, n);

    return 0;
}
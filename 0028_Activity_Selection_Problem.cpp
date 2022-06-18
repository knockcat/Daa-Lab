// Activity Selection Problem

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}

int main()
{
    // vector<int> s = {1, 3, 0, 5, 8, 5};
    // vector<int> f = {2, 4, 6, 7, 9, 9};

    vector<int> s = {1, 0, 3, 5, 3, 5, 6, 8, 8, 2, 12};
    vector<int> f = {4, 6, 5, 7, 8, 9, 10, 11, 12, 13, 14};

    // vector<int> s = {10, 12, 20};
    // vector<int> f = {20, 15, 30};

    vector<vector<int>> vp;
    int n = s.size();

    for (int i = 0; i < n; ++i)
        vp.push_back({s[i], f[i]});

    // Before Sort

    /*
    for (int i = 0; i < n; ++i)
        cout << vp[i][0] << " " << vp[i][1] << endl;
    */

    // one way of using comparator
    // sort(vp.begin(),vp.end(),compare);

    // another way of using comparator
    sort(vp.begin(), vp.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    // After Sort

    /*
    for (int i = 0; i < n; ++i)
        cout << vp[i][0] << " " << vp[i][1] << endl;
    */

    int take = 1;
    int end = vp[0][1];

    for (int i = 1; i < n; ++i)
    {
        if (vp[i][0] >= end)
        {
            ++take;
            end = vp[i][1];
        }
    }

    cout << "Maximum Activities : " << take << endl;
}
// Fractional KnapSack

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, double> a, const pair<int, double> b)
{
    return a.second > b.second;
}

int main()
{
    int n; // number of items;
    // vector<int> val = {60, 100, 120};
    vector<int> val = {21, 24, 12, 40, 30};
    // vector<int> wt = {10, 20, 30};
    vector<int> wt = {7, 4, 6, 5, 6};
    int W = 20;
    n = wt.size();
    int ans = 0;
    vector<pair<int, double>> vp;

    for (int i = 0; i < n; ++i)
    {
        vp.push_back({i, (double)val[i] / wt[i]});
    }

    // vector of pair before sorting

    /*
    for (int i = 0; i < n; ++i)
        cout << vp[i].first << " " << vp[i].second << endl;
    */

    // cout << "After sort" << endl;

    sort(vp.begin(), vp.end(), compare);

    /*
    for (int i = 0; i < n; ++i)
        cout << vp[i].first << " " << vp[i].second << endl;
    */

    for (int i = 0; i < n; ++i)
    {
        if (W >= wt[vp[i].first])
        {
            ans += val[vp[i].first];
            W -= wt[vp[i].first];
            continue;
        }
        ans += W * vp[i].second;
        break;
    }

    cout << "Maximum Value " << ans << endl;
}
// Job Sequencing

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int> a, const pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    // vector<string> Jobs = {"J1", "J2", "J3", "J4", "J5"};

    // vector<int> Profit = {100, 19, 27, 25, 15};                          //ans = 142     J3 J1 J5
    // vector<int> Deadline = {2, 1, 2, 1, 3};

    // vector<int> Profit = {20, 15, 10, 5, 1};                             // ans = 40     J2 J1 J4
    // vector<int> Deadline = {2, 2, 1, 3, 3};

    vector<string> Jobs = {"J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8"}; // ans = 322    J8 J6 J5 J2 J4 J3
    vector<int> Profit = {20, 60, 70, 65, 25, 80, 10, 22};
    vector<int> Deadline = {4, 5, 6, 6, 4, 2, 2, 2};

    int n = Jobs.size();
    int ind = 0;

    // Creating Slot Of Max Job Deadline
    vector<string> slot(*max_element(Deadline.begin(), Deadline.end()) + 1, "-1");
    slot[0] = "occupied";

    vector<pair<int, int>> vp;

    for (int i = 0; i < n; ++i)
    {
        vp.push_back({i, Profit[i]});
    }

    // Vector of pair before Sorting

    /*
    for (int i = 0; i < n; ++i)
        cout << vp[i].first << " " << vp[i].second << endl;
    */

    // cout << "After Sort" << endl;

    sort(vp.begin(), vp.end(), compare);

    /*
    for (int i = 0; i < n; ++i)
        cout << vp[i].first << " " << vp[i].second << endl;
    */

    for (int i = 0; i < n; ++i)
    {
        if (slot[Deadline[vp[i].first]] == "-1")
        {
            slot[Deadline[vp[i].first]] = Jobs[vp[i].first];
            ind += vp[i].second;
            continue;
        }

        int index = Deadline[vp[i].first];

        for (int j = index - 1; j > 0; --j)
        {
            if (slot[j] == "-1")
            {
                slot[j] = Jobs[vp[i].first];
                ind += vp[i].second;
                break;
            }
        }
    }

    cout << "Maximum Profit Sequence of Jobs \n";
    for (int i = 1; i < slot.size(); ++i)
        cout << slot[i] << " ";
    cout << endl;

    cout << "Maximum Profit " << ind << endl;
}

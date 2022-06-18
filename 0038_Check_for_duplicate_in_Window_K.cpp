// Check for Duplicate Element within window of size K < n

// TC = O(n);
// SC = O(n);

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool CheckDuplicate(vector<int> v, int k)
{
    unordered_set<int> s;

    for (int i = 0; i < v.size(); ++i)
    {
        if (s.find(v[i]) != s.end())
            return true;
        s.insert(v[i]);
        if (i >= k)
            s.erase(v[i - k]);
    }
    return false;
}

int main()
{
    vector<int> v = {10, 5, 3, 4, 3, 5, 6};
    int win = 3;

    if (CheckDuplicate(v, win))
        cout << "Yes, Exist" << endl;
    else
        cout << "No, Not Exist" << endl;

    return 0;
}
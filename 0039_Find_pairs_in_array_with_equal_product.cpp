// Find Pairs in an array such that two pairs have same product

// TC = O(n^2)
// SC = O(n)

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

void findPairs(vector<int> v)
{
    unordered_map<int, pair<int, int>> m;
    bool ind = false;

    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = i + 1; j < v.size(); ++j)
        {
            long prod = v[i] * v[j];

            if (m.find(prod) == m.end())
                m[prod] = make_pair(i, j);
            else
            {
                pair<int, int> p = m[prod];
                cout << v[p.first] << " " << v[p.second] << " and " << v[i] << " " << v[j] << endl;
                ind = true;
            }
        }
    }
    if (!ind)
        cout << "No Pair Found" << endl;
}

int main()
{
    vector<int> v = {31, 23, 4, 1, 39, 2, 20, 27, 9, 10};
    // vector<int> v = {3, 4, 7, 1, 2, 9, 8};

    findPairs(v);

    return 0;
}

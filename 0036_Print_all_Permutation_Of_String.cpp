// Print all Permutaion of a String

#include <iostream>
#include <vector>
using namespace std;

/*
void GeneratePermutation(string ds, string str, vector<string> &ans, vector<int> &freq)
{
    if (ds.size() == str.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < str.size(); ++i)
    {
        if (!freq[i])
        {
            ds.push_back(str[i]);
            freq[i] = 1;
            GeneratePermutation(ds, str, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

int main()
{
    string str = "ABC";
    vector<string> ans;
    string ds;
    vector<int> freq(str.size(), 0);

    GeneratePermutation(ds, str, ans, freq);

    cout << "Permutaions of String : " << endl;

    for (auto i : ans)
        cout << i << endl;

    return 0;
}
*/

// Another Aproach

void GeneratePermutation(int index, string str, vector<string> &ans)
{
    if (index == str.size())
    {
        ans.push_back(str);
        return;
    }

    for (int i = index; i < str.size(); ++i)
    {
        swap(str[index], str[i]);
        GeneratePermutation(index + 1, str, ans);
        swap(str[index], str[i]);
    }
}

int main()
{
    string str = "ABC";
    vector<string> ans;

    GeneratePermutation(0, str, ans);

    cout << "Permutaions of String : " << endl;

    for (auto i : ans)
        cout << i << endl;

    return 0;
}
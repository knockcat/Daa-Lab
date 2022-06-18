// Distinct characters from the array of characters

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string str = "knockcat";
    unordered_map<char, int> m;

    for (auto i : str)
        ++m[i];

    cout << "Distinct Characters : " << endl;
    for (auto i : m)
        cout << i.first << endl;

    return 0;
}
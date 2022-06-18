// Longest Common Subsequence

// recursive code

/*#include <iostream>
using namespace std;

int LCS(string str1, string str2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (str1[m - 1] == str2[n - 1])
        return 1 + LCS(str1, str2, m - 1, n - 1);
    else
        return max(LCS(str1, str2, m - 1, n), LCS(str1, str2, m, n - 1));
}

int main()
{
    string str1 = "abcdgh";
    string str2 = "abedfhr";

    int m = str1.length();
    int n = str2.length();

    cout << "Length of LCS is " << LCS(str1, str2, m, n);

    return 0;
}*/

// memoised code (top - down)

/*#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> t(1001, vector<int>(1001, -1));
int LCS(string str1, string str2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (t[m][n] != -1)
        return t[m][n];

    if (str1[m - 1] == str2[n - 1])
        return t[m][n] = 1 + LCS(str1, str2, m - 1, n - 1);
    else
        return t[m][n] = max(LCS(str1, str2, m - 1, n), LCS(str1, str2, m, n - 1));
}

int main()
{
    string str1 = "abcdgh";
    string str2 = "abedfhr";

    int m = str1.length();
    int n = str2.length();

    cout << "Length of LCS is " << LCS(str1, str2, m, n);

    return 0;
}*/

// bottom up (dp-tabulation)

#include <iostream>
#include <vector>
using namespace std;

int LCS(string str1, string str2, int m, int n)
{
    vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < m + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < m + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }

    return t[m][n];
}

int main()
{
    string str1 = "abcdgh";
    string str2 = "abedfhr";

    int m = str1.length();
    int n = str2.length();

    cout << "Length of LCS is " << LCS(str1, str2, m, n);

    return 0;
}
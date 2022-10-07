#include <bits/stdc++.h>
using namespace std;
int minDis(string s1, string s2, int n, int m,
           vector<vector<int>> &dp)
{

    // If any string is empty,
    // return the remaining characters of other string

    if (n == 0)
        return m;

    if (m == 0)
        return n;

    // To check if the recursive tree
    // for given n & m has already been executed

    if (dp[n][m] != -1)
        return dp[n][m];

    // If characters are equal, execute
    // recursive function for n-1, m-1

    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] = minDis(s1, s2, n - 1, m - 1, dp);
    }
    // If characters are nt equal, we need to
    // find the minimum cost out of all 3 operations.
    // 1. insert 2.delete 3.replace
    else
    {
        int insert, del, replace; // temp variables

        insert = minDis(s1, s2, n, m - 1, dp);
        del = minDis(s1, s2, n - 1, m, dp);
        replace = minDis(s1, s2, n - 1, m - 1, dp);
        return dp[n][m] = 1 + min(insert, min(del, replace));
    }
}

// Driver program
int main()
{

    string str1 = "voldemort";
    string str2 = "dumbledore";

    int n = str1.length(), m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << minDis(str1, str2, n, m, dp);
    return 0;

}

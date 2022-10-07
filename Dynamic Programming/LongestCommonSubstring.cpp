// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the
// longest LCS
int LCSubStr(string s, string t, int n, int m)
{

    // Create DP table
    int dp[2][m + 1];
    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                if (dp[i % 2][j] > res)
                    res = dp[i % 2][j];
            }
            else
                dp[i % 2][j] = 0;
        }
    }
    return res;
}

// Driver Code
int main()
{
    string X = "OldSite:heyThisIslakshay.org";
    string Y = "NewSite:MynameISLAkshay.com";

    int m = X.length();
    int n = Y.length();

    cout << LCSubStr(X, Y, m, n);
    return 0;
    cout << "GFG!";
    return 0;
}

// C++ program to find minimum number of trials in worst
// case.
#include <bits/stdc++.h>
using namespace std;

int minTrials(int n, int k)
{
    // Initialize array of size (n+1) and m as moves.
    int dp[n + 1] = {0}, m;
    for (m = 0; dp[n] < k; m++)
    {
        for (int x = n; x > 0; x--)
        {
            dp[x] += 1 + dp[x - 1];
        }
    }
    return m;
}

/* Driver code*/
int main()
{
    cout << minTrials(2, 10);
    return 0;
}

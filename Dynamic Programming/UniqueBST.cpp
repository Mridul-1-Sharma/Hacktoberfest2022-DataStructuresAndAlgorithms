// C++ code to find number of unique BSTs
// Dynamic Programming solution
#include <bits/stdc++.h>
using namespace std;

// Function to find number of unique BST
int numberOfBST(int n)
{

    // DP to store the number of unique BST with key i
    int dp[n + 1];
    fill_n(dp, n + 1, 0);

    // Base case
    dp[0] = 1;
    dp[1] = 1;

    // fill the dp table in bottom-up approach.
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {

            // n-i in right * i-1 in left
            dp[i] = dp[i] + (dp[i - j] * dp[j - 1]);
        }
    }

    return dp[n];
}

// Driver Code
int main()
{
    int N = 3;

    // Function call
    cout << "Number of structurally Unique BST with " << N
         << " keys are : " << numberOfBST(N) << "\n";

    return 0;
}

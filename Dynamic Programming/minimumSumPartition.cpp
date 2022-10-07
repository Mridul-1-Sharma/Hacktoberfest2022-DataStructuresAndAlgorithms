#include <iostream>
using namespace std;

int minDifference(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int y = sum / 2 + 1;
    // dp[i] gives whether is it possible to get i as sum of
    // elements dd is helper variable
    // we use dd to ignoring duplicates
    bool dp[y], dd[y];

    // Initialising dp and dd
    for (int i = 0; i < y; i++)
    {
        dp[i] = dd[i] = false;
    }

    // sum = 0 is possible
    dd[0] = true;
    for (int i = 0; i < n; i++)
    {
        // updating dd[k] as true if k can be formed using
        // elements from 1 to i+1
        for (int j = 0; j + arr[i] < y; j++)
        {
            if (dp[j])
                dd[j + arr[i]] = true;
        }
        // updating dd
        for (int j = 0; j < y; j++)
        {
            if (dd[j])
                dp[j] = true;
            dd[j] = false; // reset dd
        }
    }
    // checking the number from sum/2 to 1 which is possible
    // to get as sum

    for (int i = y - 1; i >= 0; i--)
    {
        if (dp[i])
            return (sum - 2 * i);
        // since i is possible to form then another number
        // is sum-i
        // so mindifference is sum-i-i
    }
}
int main()
{

    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The Minimum difference of 2 sets is "
         << minDifference(arr, n) << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid, int n) // n is the stalls sizes
{

    int cowCount = 1;
    int lastPos = stalls[0]; // here we have placed out first cow at position zero

    // In this loop we are checking byb placing our cow so that the diference btw the lastPos and the current array element is == mid  if it is true
    //   1. we increment our cowCount 2. check if (cowCount == k) return false 3. update the posotion of the first Cow to check other iterations

    for (int i = 0; i < n; i++)
    {

        if (stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int n = stalls.size();
    int e = stalls[n - 1];
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (isPossible(stalls, k, mid, n))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

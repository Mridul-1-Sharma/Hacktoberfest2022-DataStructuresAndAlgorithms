#include <bits/stdc++.h>
using namespace std;
/*
int min_elem(int a[], int n)
{
    int min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
} */

void fun()
{
    int n;
    cin >> n;
    int a[n];
    // int coin_count = 0;
    int avg_of_coins = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        avg_of_coins += a[i];
    }
    avg_of_coins = avg_of_coins / 2;
    sort(a, a + n);
    int j = 0;
    int b[n];
    for (int i = n - 1; i >= 0; i--)
    {
        b[j] = a[i];
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }

    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ++count;
        if (sum > avg_of_coins)
        {
            cout << count << endl;
            return;
        }
    }
}
int main()
{

    // long long int t;
    // cin >> t;
    // while (t--)
    // {
    fun();
    // }
    return 0;
}
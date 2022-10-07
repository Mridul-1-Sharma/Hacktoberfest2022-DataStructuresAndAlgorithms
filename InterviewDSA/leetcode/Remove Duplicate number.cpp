#include <iostream>
#include <vector>
using namespace std;

void removeduplicatenumber(vector<int> v)
{
    int i, j;
    int a = v.size();
    for (i = 0; i < a; i++)
    {
        for (j = i + 1; j < a; j++)
        {
            if (v[i] == v[j])
            {
                for (int k = j; k < a - 1; k++)
                {
                    v[k] = v[k + 1];
                }

                a--;
                j--;
            }
        }
    }
    for (i = 0; i < a; i++)
    {
        cout << v[i];
    }
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 2, 3, 5, 5, 3, 3, 7, 6};
    removeduplicatenumber(v);
}

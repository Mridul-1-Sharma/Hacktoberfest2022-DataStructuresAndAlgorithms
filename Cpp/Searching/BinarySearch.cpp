#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int s = 0;
    int e = n;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        else if (arr[mid] > key)
        {
            e = mid - 1;
        }

        else
        {
            s = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    int iRet = 0;
    cout<<"Enter size of array: -"<<endl;
    cin >> n;

    int arr[n];
   
    for (int i = 0; i < n; i++)
    {
	  cout<<"Enter "<<i + 1<<" Element in array: -"<<endl;
        cin>>arr[i];
    }

    int key;
    cout<<"Enter element to search in array: -"<<endl;
    cin >> key;
     

    iRet = binarySearch(arr, n, key);

    if(iRet == -1)
    {
	cout<<"Element is not present in the array !"<<endl;
    }
    else
    {
	cout<<"Element is present in the array !"<<endl;
    }

    return 0;
}
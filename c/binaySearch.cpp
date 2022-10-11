#include <iostream>
using namespace std;
int main()
{

    int num, arr[] = {1, 12, 23, 34, 45, 56, 67, 78, 89, 910};

    cout << "enter the number you want to search for \n";
    cin >> num;

    int first = 0;
    int last = 9;

    int mid = (first + last) / 2;

    while (first <= last)
    {

        if (arr[mid] < num)
        {
            first = mid + 1;
        }
        else if (arr[mid] == num)
        {
            cout << "the number :" << num << " is at index " << mid;
            break;
        }
        else
        {
            last = mid - 1;
        }
        mid = (first + last) / 2;
    }
    if (first > last)
        cout << "number doest not exist in array";
}
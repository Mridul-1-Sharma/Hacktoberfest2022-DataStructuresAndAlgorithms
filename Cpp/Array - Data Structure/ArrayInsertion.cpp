#include <iostream>
using namespace std;
//traversal code
void dispaly(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
//insertion code
int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index - 1; i--) //here i=size or size-1
    {
        arr[i + 1] = arr[i];
    }
    arr[index - 1] = element;
    size++;
    return 1;
}
//deletion code
int indexdeletion(int arr[], int size, int ind)
{
    for (int i = ind; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}
int main()
{
    int arr[100] = {1, 2, 3, 6, 10, 17};
    int size = 6, element = 1, index = 5, ind = 2;
    dispaly(arr, size);
    cout << "insertion\n";
    indInsertion(arr, size, element, 100, index);
    size += 1;
    dispaly(arr, size);
    cout << "deletion\n";
    indexdeletion(arr, size, ind);
    size -= 1;
    dispaly(arr, size);
    return 0;
}

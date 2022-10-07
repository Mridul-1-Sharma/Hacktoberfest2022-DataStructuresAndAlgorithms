#include <bits/stdc++.h>
using namespace std;

void heapify(vector < int >& arr, int i){
    int largest = i, l = 2 * i + 1, r = 2 * i + 2, n = arr.size();
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, largest);
    }
}

void heapSort(vector < int >& arr){
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0);
    }
}

int main(){
    
    return 0;
}
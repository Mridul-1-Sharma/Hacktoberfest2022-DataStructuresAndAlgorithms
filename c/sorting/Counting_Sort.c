#include <stdio.h>
#include <limits.h>

void countSort(int* arr, int n){
    int max = INT_MIN, min = INT_MAX;
    int range = max - min + 1;
    int count[range], output[n];
    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main(){

    return 0;
}
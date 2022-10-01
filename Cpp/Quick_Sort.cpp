#include <bits/stdc++.h>
using namespace std;

int Partition(vector < int >& nums, int l, int r){
    int pivot = nums[r], i = l;
    for(int j = l; j < r; j++){
        if(nums[j] <= pivot)
            swap(nums[i++], nums[j]);
    }
    swap(nums[i], nums[r]);
    return i;
}

void Quick_Sort(vector < int >& nums, int l, int r){
    if(l >= r) return;
    int pivot = Partition(nums, l, r);
    Quick_Sort(nums, l, pivot - 1);
    Quick_Sort(nums, pivot + 1, r);
}

int main(){

   return 0;
}
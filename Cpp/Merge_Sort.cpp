#include <bits/stdc++.h>
using namespace std;

void Merge(int l, int m, int r, vector < int >& nums){
    int sz_1 = m - l + 1, sz_2 = r - m;
    vector < int > left(sz_1), right(sz_2);
    for(int i = 0; i < sz_1; i++) left[i] = nums[l + i];
    for(int i = 0; i < sz_2; i++) right[i] = nums[m + 1 + i];
    int i = 0, j = 0, k = l;
    while(i < sz_1 && j < sz_2)
        nums[k++] = (left[i] <= right[j] ? left[i++] : right[j++]);
    while(i < sz_1) nums[k++] = left[i++];
    while(j < sz_2) nums[k++] = right[j++];
}

void Merge_Sort(vector < int >& nums, int l, int r){
    if(l >= r) return;
    int m = l + (r - l) / 2;
    Merge_Sort(nums, l, m);
    Merge_Sort(nums, m + 1, r);
    Merge(l, m, r, nums);
}

int main(){

    return 0;
}
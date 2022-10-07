#include <bits/stdc++.h>
using namespace std;

void Insertion_Sort(vector < int >& nums){
    int n = nums.size();
    for(int i = 1; i < n; i++){
        int value = nums[i], j = i - 1;
        while(j >= 0 && nums[j] > value)
            nums[j + 1] = nums[j], j--;
        nums[j + 1] = value;
    }
}

int main(){

    return 0;
}

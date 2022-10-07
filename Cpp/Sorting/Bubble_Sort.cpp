#include <bits/stdc++.h>
using namespace std;

void Bubble_Sort(vector < int >& nums){
    int n = nums.size();
    for(int i = 0; i < n - 1; i++){
        bool is_sorted = true;
        for(int j = 0; j < n - i - 1; j++){
            if(nums[j] < nums[j + 1])
                swap(nums[j], nums[j + 1]), is_sorted = false;
        }
        if(is_sorted) return;
    }
}

int main(){
    
    return 0;
}

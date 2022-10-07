// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Input: nums = [1,3,5,6], target = 2
// Output: 1

// C++ solution using Binary search

#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size();
        int mid;
        if(target>nums[nums.size()-1])
            return nums.size();
        if(target<nums[0])
            return 0;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else
            if(target<nums[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        if(target>nums[mid])
        return mid+1;
        else
            return mid;
    }
    int main()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(3);
        v.push_back(5);
        v.push_back(6);
        cout<<searchInsert(v,2);
        return 0;
    }

    // Output: 1
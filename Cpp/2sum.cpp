#include<bits/stdc++.h>
using namespace std;

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        //Key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) {
                return {hash[numberToFind], i};
            }

            //number was not found. Put it in the map.
            hash[numbers[i]] = i;
        }
        return result;
    }
};

int main() {
    vector<int>nums = {2, 7, 11, 15};
    int target = 9;
    Solution obj;
    vector<int>ans = obj.twoSum(nums, target);
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

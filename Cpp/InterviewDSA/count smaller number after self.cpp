#include <bits/stdc++.h>
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
void merge(vector<pii>&vec,vector<pii>&temp, int s,int mid, int e,vi&ans){
        int n = ans.size();
        int i = s, j = mid+1,cnt = 0;
        int idx = s;
        while(i<=mid or j<=e){
            if(i>mid){
                while(j<=e){
                    temp[idx++] = vec[j];
                    j++;
                }
                continue;
            }
            if(j>e){
                while(i<=mid){
                    ans[vec[i].second] += cnt;
                    temp[idx++] = vec[i]; 
                    i++;
                }
                continue;
            }
            
            if(vec[i].first <= vec[j].first){
                temp[idx++] = vec[i];
                ans[vec[i].second] += cnt;  
                i++;
            }
            else{
                temp[idx++] = vec[j];
                cnt++;
                j++;
            }
        }
        for(int i = s; i<=e; i++){
            vec[i] = temp[i];
        }
        
    }
    void merge_sort(vector<pii>&vec,vector<pii>&temp,int s, int e, vector<int>&ans){
        if(s == e)return;
        int mid = s +(e-s)/2;
        merge_sort(vec,temp,s,mid,ans);
        merge_sort(vec,temp,mid+1,e,ans);
        merge(vec,temp,s,mid,e,ans);
    }
    vi countSmaller(vi& nums) {
        vector<pii>vec;
        vector<pii>temp;
        for(int i = 0; i<nums.size(); i++){
            vec.push_back({nums[i],i});
        }
        temp = vec;
        vi ans(nums.size(),0);
        merge_sort(vec,temp,0,nums.size()-1,ans);
        return ans;
    }
    int main(){
        vi nums  {5,2,6,1};
        int sz = nums.size();
        vi ans = countSmaller(nums);
        for(auto x:ans){
            cout<<x<<" ";
        }
        
        
        return 0;
    }
    

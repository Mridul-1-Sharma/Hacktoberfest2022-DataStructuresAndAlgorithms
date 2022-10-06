// Name of Problem = Permutation Sequence

// Problem Link : https://leetcode.com/problems/permutation-sequence/


class Solution {
public:
    string getPermutation(int n, int k) {
        int d = n-1;
        int t = k;
        list<char> nums;
        string result = "";
        for(int i = 1; i <= n; i++){
            nums.push_back(i+48);
        }
        while(t!=0){
            int jd = jiecheng(d);
            int position = ceil((double)t/jd);
            auto it = nums.begin();
            for(int i = 0; i< position-1 && it != nums.end(); i++, it++);
            result += *it;
            nums.remove(*it);
            //cout<<t<<" "<<jd<<" "<<position<<" "<<t<<endl;
            t = t%jd; 
            d--;
        }
        nums.reverse();
        for(auto it = nums.begin(); it != nums.end(); it++){
            result += *it;
        }
        return result;
    }
    int jiecheng(int n){
        if(n == 0)return 1;
        int sum = n;
        while(--n > 0) sum*=n;
        return sum;
    }
};
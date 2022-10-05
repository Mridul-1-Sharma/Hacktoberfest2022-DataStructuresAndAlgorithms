#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n);
        stack<int>l;
        for(int i = 0; i<n; i++){
            if(l.empty()) left[i] = 0;
            else{
                while(!l.empty() and heights[l.top()] >= heights[i])  l.pop();  
                left[i] = (l.empty()) ? 0 : l.top() + 1;
            }
            l.push(i);
        }
        vector<int>right(n);
        stack<int>r;
        for(int i = n-1; i>=0 ; i--){
            if(r.empty()) right[i] = n-1;
            else{
                while(!r.empty() and heights[r.top()] >= heights[i]) r.pop();
                right[i] = (r.empty()) ? n-1 : r.top() - 1;
            }
            r.push(i);
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, (right[i] - left[i] + 1)*heights[i]);
        }
        return ans;
}

int main(){
    vector<int>heights{2,1,5,6,2,3,3,5};
    int sz = heights.size();
    cout<<largestRectangleArea(heights);
    return 0;
}

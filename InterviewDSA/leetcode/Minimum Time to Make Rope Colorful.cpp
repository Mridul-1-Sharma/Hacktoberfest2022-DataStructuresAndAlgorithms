class Solution {
public:
    struct node{
        char c;
        int val;
    };
    
    int minCost(string s, vector<int>& cost) {
        stack<node> stack;
        int n=s.size(), result=0;
        
        for(int i=0; i<n; i++){
            if(!stack.empty() && stack.top().c==s[i]){
                if(stack.top().val<cost[i]){
                    result+=stack.top().val;
                    stack.pop();
                    stack.push({s[i], cost[i]});
                }
                else{
                    result+=cost[i];
                }
            }
            else{
                stack.push({s[i], cost[i]});
            }
        }
        
        return result;
    }
};

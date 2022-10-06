// Name of Problem = Expression Add Operator

// Problem Link : https://leetcode.com/problems/expression-add-operators/



typedef long long int Int64;

class Solution {
private:
    const char *numstr;
    Int64 target64;
    int n;
    
    void dfs(Int64 prev, Int64 curr, int next, char* buffer, int buffernext, vector<string>& res)
    {
        if(next == n)
        {
            buffer[buffernext] = '\0';
            if(prev+curr == target64)
            {
                string s = buffer;
                res.push_back(s);
            }
            return;
        }
        
        int lm;
        if(numstr[next] == '0')
            lm = next+1;
        else
            lm = n;
        
        int l;
        Int64 v=0;
        for(l=next; l<lm; l++)
        {
            buffer[buffernext+l-next+1] = numstr[l];
            v = v*10 + (numstr[l] - '0');
            
            buffer[buffernext] = '+';
            dfs(prev+curr, v, l+1, buffer, buffernext+l-next+2, res);
            
            buffer[buffernext] = '-';
            dfs(prev+curr, -v, l+1, buffer, buffernext+l-next+2, res);
            
            buffer[buffernext] = '*';
            dfs(prev, curr*v, l+1, buffer, buffernext+l-next+2, res);
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        
        n = num.size();
        target64 = (Int64) target;
        numstr = num.c_str();
        
        char buf[2*n];
        int lmax;
        if(numstr[0] == '0') // A number starts with '0' must be 0
            lmax = 1;
        else
            lmax = n;
        int i;
        Int64 previous = 0;
        Int64 current = 0;
        for(i=0; i<lmax; i++)
        {
            current = current*10 + (numstr[i] - '0');
            buf[i] = numstr[i];
            dfs(previous, current, i+1, buf, i+1, result);
        }
        return result;
    }
};

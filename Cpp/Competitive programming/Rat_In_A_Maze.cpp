#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> ans;
    bool isvalid(int i,int j,int n,vector<vector<int>> &m)
    {
        if(i<0 || j<0 || i>=n || j>=n || m[i][j]==0)return false;
        return true;
    }
    void helper(string s,int i,int j,int n,vector<vector<bool>> &vis,vector<vector<int>> &m)
    {
        if(!isvalid(i,j,n,m))return;
        if(vis[i][j])return;
        if(i==n-1 && j==n-1){ans.push_back(s);return;}
        vis[i][j]=true;
        helper(s+"D",i+1,j,n,vis,m);
        helper(s+"R",i,j+1,n,vis,m);
        helper(s+"U",i-1,j,n,vis,m);
        helper(s+"L",i,j-1,n,vis,m);
        vis[i][j]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>> vis(n+1,vector<bool>(n+1,false));
        helper("",0,0,n,vis,m);
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}

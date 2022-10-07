// Problem Link : https://leetcode.com/problems/game-of-life/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        
  
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int top=i-1>=0 ? a[i-1][j]&1:0 ;
                int down=i+1<n ? a[i+1][j]&1:0;
                int left=j-1>=0?a[i][j-1]&1:0;
                int right=j+1<m? a[i][j+1]&1:0;
                int topl=i-1>=0 and j-1>=0 ?a[i-1][j-1]&1:0;
                int topr=i-1>=0 and j+1<m ? a[i-1][j+1]&1:0;
                int bl=i+1<n and j-1>=0 ?a[i+1][j-1]&1:0;
                int br=i+1<n and j+1<m ? a[i+1][j+1]&1:0;
                
                int count=top+down+left+right+topl+topr+bl+br;
                
                if(a[i][j]==1  and count>=2 and count<=3)
                    a[i][j]=3;
                
                if(a[i][j]==0 and count==3)
                    a[i][j]=2;
                }

            }
   
   
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[i][j]>>=1;
    }
};

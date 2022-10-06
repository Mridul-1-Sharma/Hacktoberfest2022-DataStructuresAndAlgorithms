// Problem Link : https://leetcode.com/problems/longest-happy-prefix/

class Solution {
public:
    string longestPrefix(string s) {
        long n=s.length();
        long i=1;
		
		int lps[n];
		
        long len=0;    
        
        lps[0]=len;      
        
        while(i<n)
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)    
                {
                    len=lps[len-1];     
                }
                else
                {
                    lps[i]=0;       
                    i++;
                }
            }
        }
		 	
        return s.substr(0,lps[n-1]);        
        
    }
};
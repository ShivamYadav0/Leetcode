class Solution {
public:
    
    int countSubstrings(string s) {
        int ans=0;
        int n=s.length();
       vector<vector<bool>>dp(n, vector<bool>(n,0));
        
        for(int i=0;i<n;i++){
             dp[i][i]=1;
           
        }
           
        for(int i=0;i<n-1;i++){
           
                  dp[i][i+1]=(s[i]==s[i+1]);
              
              
        }
        for(int i=2;i<n;i++){
            for(int j=0;j<n-i;j++){
              
                    dp[j][j+i]=(s[j]==s[j+i]&&dp[j+1][i+j-1]);
                    
            }
        }
        ans=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                ans+=(dp[j][j+i]);
            }
         }
        return ans;
    }
};
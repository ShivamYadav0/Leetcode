class Solution {
public:
    
    int countSubstrings(string s) {
        int ans=0;
        int n=s.length();
       vector<vector<bool>>dp(n, vector<bool>(n,0));
        
        for(int i=0;i<n;i++){
             dp[i][i]=1;
            ans++;
        }
           
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                  dp[i][i+1]=1;
                ans++;
            }
              
        }
        for(int i=2;i<n;i++){
            for(int j=0;j<n-i;j++){
                if(s[j]==s[j+i]&&dp[j+1][i+j-1]){
                    dp[j][j+i]=1;
                    ans++;
                }
            }
        }
        ans=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                if(dp[j][j+i])ans++;
            }
         }
        return ans;
    }
};
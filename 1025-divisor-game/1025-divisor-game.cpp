class Solution {
public:
    int dp[1001];
    bool check(int n){
        if(n==1)return false;
        if(dp[n]!=-1)return dp[n];
        for(int j=1;j<n;j++){
            if(n%j==0){
                if(!check(n-j))
                    return dp[n]=true;
            }
        }
        return dp[n]=false;
    }
    bool divisorGame(int n) {
        memset(dp,-1,sizeof(dp));
        return check(n);          
    } 
};
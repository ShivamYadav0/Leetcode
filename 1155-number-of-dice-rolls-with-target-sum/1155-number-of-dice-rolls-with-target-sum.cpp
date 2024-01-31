class Solution {
public:
    long long md=1e9+7;
    vector<vector<long long>>dp;
    long long rec(int i,int k,int t){
        if(t<0)return 0;
        if(i==0){
            return t==0;
        }
        if(dp[i][t]!=-1)return dp[i][t];
        long long ans=0;
        for(int j=1;j<=k;j++){
            ans=ans+rec(i-1,k,t-j)%md;
            ans%=md;
        }
        return dp[i][t]=ans;
        
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1,vector<long long>(target+1,-1));
        
        return rec(n,k,target);
    }
};
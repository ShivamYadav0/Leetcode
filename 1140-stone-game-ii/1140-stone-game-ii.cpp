class Solution {
public:
    int dp[101][101];
    int rec(int i,int m,vector<int>&p){
        if(i>=p.size())return 0;
        if(dp[i][m]!=-1)return dp[i][m];
        int lt=i+2*m;
        if(lt>=p.size())lt=p.size();
        int ans=1e7;
        int cs=0;
        int ts=0;
        for(int j=i;j<p.size();j++)ts+=p[j];
        for(int j=i;j<lt;j++){
            //ts+=p[j];
            cs+=p[j];
            int rans=rec(j+1,max(m,j-i+1),p);
            //cout<<rans+cs<<" ";
            ans=min(ans,rans);
            
        }
        return dp[i][m]=ts-ans;
    }
    int stoneGameII(vector<int>& piles) {
      memset(dp,-1,sizeof(dp));
        int ts=0;
        for(auto x:piles)ts+=x;
        return rec(0,1,piles);
    }
};
class Solution {
public:
    int md=1e9+7;
    int dp[23][2][24*9];
    long long rec(string &st,int i,int s,bool tt,int mn,int mx){
        if(i==st.length()){
            if(s>=mn&&s<=mx)return 1;
            return  0;
        }
        if(dp[i][tt][s]!=-1){
            return dp[i][tt][s];
        }
        int lt=tt?st[i]-'0':9;
        long long ans=0;
        for(int j=0;j<=lt;j++){
            ans=ans%md+rec(st,i+1,s+j,tt&&j==lt,mn,mx)%md;
            ans%=md;
        }
        return  dp[i][tt][s]=ans;
    }
        
    int count(string num1, string num2, int mn, int mx) {
        memset(dp,-1,sizeof(dp));
        long long r=rec(num2,0,0,1,mn,mx)%md;
        memset(dp,-1,sizeof(dp));
        long long l=rec(num1,0,0,1,mn,mx)%md;
      //  cout<<r<<" "<<l<<endl;
        bool check=0;
        int s=0;
        for(auto x:num1)s+=(x-'0');
        if(s>=mn&&s<=mx)check=true;
        long long ans=(r-l+check)%md;
        if(ans<0)ans+=md;
        return ans;
    }
};
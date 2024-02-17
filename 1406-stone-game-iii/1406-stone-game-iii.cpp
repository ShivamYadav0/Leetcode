class Solution {
public:
     vector<int>ss;
     vector<vector<int>>dpp;
     vector<int>dp;
    int limit=-1e8;
    int rec(int i,vector<int>&v){
         if(i==v.size())return 0;
        //int ans=0;
        if(dp[i]!=limit)return dp[i];
        int lt=i+3;
        if(lt>=v.size())lt=v.size();
        int s=0;
        int ans=-limit;
        for(int j=i;j<lt;j++){
            s+=v[j];
            ans=min(ans,rec(j+1,v));
        }
        return dp[i]=ss[i]-ans;
    }
    string stoneGameIII(vector<int>& st) {
        ss=st;
        //dp.resize(st.size()+1,vector<int>(4,-1));
        dp.resize(st.size()+1,limit);
       for(int i=st.size()-2;i>=0;i--){
           ss[i]=ss[i+1]+st[i];
       }
        int ans=rec(0,st);
        if(ans*2>ss[0]){
            return "Alice";
        }
        if(ans*2<ss[0])return "Bob";
        return "Tie";
    }
};
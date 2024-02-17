class Solution {
public:
     
     vector<int>dp;
    int limit=-1e8;
    int rec(int i,vector<int>&v,int ts){
         if(i==v.size())return 0;
        //int ans=0;
        if(dp[i]!=limit)return dp[i];
        int lt=i+3;
        if(lt>=v.size())lt=v.size();
       // int s=0;
        int ans=-limit;
        for(int j=i;j<lt;j++){
            ts-=v[j];
            ans=min(ans,rec(j+1,v,ts));
            ts+=v[j];
        }
        return dp[i]=ts-ans;
    }
    string stoneGameIII(vector<int>& st) {
       
        dp.resize(st.size()+1,limit);
        int ts=0;
       for(int i=st.size()-1;i>=0;i--){
          ts+=st[i];
       }
        int ans=rec(0,st,ts);
        if(ans*2>ts){
            return "Alice";
        }
        if(ans*2<ts)return "Bob";
        return "Tie";
    }
};
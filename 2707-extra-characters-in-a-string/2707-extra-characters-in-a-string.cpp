class Solution {
public:
   vector<unordered_map<string,int>>dp;
   unordered_map<string,int>mp;
    int rec(int i, string &s,string t){
       if(i==s.length())
           return t.length();
      if(dp[i].find(t)!=mp.end())
          return dp[i][t];
      int ans=1e5;
      if(mp[t+s[i]]>0){
         ans=rec(i+1,s,"");
       }
     ans=min(ans,rec(i+1,s,t+s[i]));
        
     int ll=rec(i+1,s,"")+t.length()+1;
      ans=min(ans,ll);
      
        return dp[i][t]=ans;
        
   }
    int minExtraChar(string s, vector<string>& dictionary) {
        
      for(auto x: dictionary)
          mp[x]++;
      dp.resize(s.length()+1);
      return rec(0,s,"");
    }
};
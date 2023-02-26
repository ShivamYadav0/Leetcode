class Solution {
public:
 vector<vector<int>>dp;
 int rec(string &s, string &t,int i,int j){
   if(i>=s.length()||j>=t.length()){
if(j==t.length())
 return s.length()-i;
 return t.length()-j;
 }
     
  if(dp[i][j]!=-1)
   return dp[i][j];
   if(s[i]==t[j])
  return dp[i][j]=rec(s,t,i+1,j+1);
   
  int ans=min(rec(s,t,i+1,j),rec(s,t,i,j+1))+1;
  ans=min(ans,rec(s,t,i+1,j+1)+1);
  return dp[i][j]=ans;
}
    int minDistance(string w1, string w2) {
     dp.resize(w1.length()+1, vector<int>(w2.length()+1,-1));
      
  return rec(w1,w2,0,0);
    }
};
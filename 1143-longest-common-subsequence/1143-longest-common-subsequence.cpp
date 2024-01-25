class Solution {
public:
 
 int rec(vector<vector<int>>&dp,string &t1,string &t2,int i,int j){
  if(i<0 || j<0)
  return 0;
  if(dp[i][j]!=-1)
    return dp[i][j];
  if(t1[i]==t2[j]){
   return dp[i][j]=1+rec(dp,t1,t2,i-1,j-1);
  }
 return dp[i][j]=max(rec(dp,t1,t2,i-1,j),rec(dp,t1,t2,i,j-1));
}
    int longestCommonSubsequence(string t1, string t2) {
 vector<vector<int>>dp(t1.size(), vector<int>(t2.size(),-1));
 return 
   rec(dp,t1,t2,t1.size()-1,t2.size()-1); 
        
  }
};
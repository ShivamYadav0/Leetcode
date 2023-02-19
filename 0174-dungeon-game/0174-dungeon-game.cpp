class Solution {
public:
    vector<vector<int>>dp;
    
 int rec(vector<vector<int>>&d,int i,int j){
   if(i>=d.size()||j>=d[0].size()){
    if(i==d.size()-1||j==d[0].size()-1) return 0;
    return INT_MIN;}
   if(dp[i][j]!=1e7)
       return dp[i][j];
 
     int l=rec(d,i+1,j);
     int r=rec(d,i,j+1);
  return dp[i][j]=max(l<0?l:0,r<0?r:0)+d[i][j];
    
}
    int calculateMinimumHP(vector<vector<int>>& d) {
     dp.resize(d.size(), vector<int>(d[0].size(),
                                     1e7));
   return max(1,1-rec(d,0,0));
    }
};
class Solution {
public:
    int rec(vector<vector<int>>&dp,vector<vector<int>>&m,int i,int j){

 if(i==m.size())
  return 0;
  if(j>=m[0].size()||j<0)
 return 10000;

 if(dp[i][j]!=-100000)

   return dp[i][j];
int a=100000;
for(int k=0;k<m[0].size();k++)
{
  if(i==0 || j!=k)
  a=min(a,rec(dp,m,i+1,k)+m[i][k]);
}


    return dp[i][j]=a;

          

}


    int minFallingPathSum(vector<vector<int>>& m) {
    vector<vector<int>>dp(m.size(), vector<int>(m[0].size(),-100000));

 return rec(dp,m,0,0);
    }
};
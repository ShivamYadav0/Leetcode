class Solution {
public:
// vector<int>v;
 
int rec(vector<int>&dp,int n){
  if(n<=0) {
   if(n==0)
   return 0;
 return 1e5;
}
 if(dp[n]!=-1)
  return dp[n];
  int an=1e5;
  for(int i=1;i*i<=n;i++)
   {
an=min (an,rec(dp,n-(i*i))+1);}
 return dp[n]=an;
 
}
    
    int numSquares(int n) {
  static vector<int>dp(10001,-1);
     
 return rec(dp,n);
        
   // cout<<dp[n-1]<<endl;
  //  return dp[n];
         }
};
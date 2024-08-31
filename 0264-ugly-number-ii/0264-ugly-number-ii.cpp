class Solution {
public:
    int nthUglyNumber(int n) {
   static vector<int>p={2,3,5};
 static vector<int>v(p.size(),0);
     
   static vector<int>dp={1};

    if(dp.size()>n)
      return dp[n-1];

  while(dp.size()<n){
   long long mn=INT_MAX;
   int d;
  for(int j=0;j<p.size();j++){
 
   if(mn/p[j]>=dp[v[j]]){
    if(mn==dp[v[j]]*p[j]) 
     v[j]++;
    else 
    mn=dp[v[j]]*p[j],d=j;
    }
   }
      v[d]++;
  
  
  dp.push_back(mn);
   }
   
   
   return dp.back(); 
    }
};
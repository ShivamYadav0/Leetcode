class Solution {
public:
    long long mostPoints(vector<vector<int>>& v) {
  


long long n=v.size();
long br[n+1]; 

   br[n]=0;

   for(long i=n-1;i>=0;i--) 

   {

    long a=v[i][1]; 

    long b=v[i][0]+((i+1+v[i][1]<=n)?br[i+1+a]:0);

    long c=br[i+1];

    br[i]=max(b,c);

   } 

   return br[0];
    }
};
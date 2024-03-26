class Solution {
public:
    int firstMissingPositive(vector<int>& v) {

     
     int n=v.size();
   
    for(auto &x:v)
     if(x<=0 || x>n)
      x=n+1;
    int mx=n+2;
   
  int c=1;
  for(int i=0;i<n;i++){
  if((v[i]%mx)<=n)
   v[v[i]%mx-1]+=mx;
  }
  for(int i=0;i<n;i++){
   if(v[i]/mx>0)
    c++;
   else return c;
  }
  return c;
 }
};
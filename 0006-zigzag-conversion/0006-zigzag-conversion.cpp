class Solution {
public:
    string convert(string s, int n) {
     if(n==1) return s;
      int m=n+n-2;
    int d=m;
      
     int id=0;
     string ans;
     bool f=0;
   for(int i=0;i<n;i++){
      id=i;
      f=1;
      while(id<s.size()){
      //cout<<id<<" ";
      ans+=s[id];
      if(d==0 || d==m)
      id+=m;
      else if(f)
      id+=d,f=0;
      else id+=m-d,f=1;
     }
    // cout<<endl;
      d=d-2;
  }
 return ans;
 }
};
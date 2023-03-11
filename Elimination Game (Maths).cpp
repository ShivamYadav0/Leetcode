class Solution {
public:
 int rec(int a,int b,int d,bool f,int n){
     if(n==1) return a;
   if(!f){
      bool g=(n%2);
return rec(a+d,g?b-d:b,2*d,!f,n/2);
    
      }
  bool g=(n%2);
  return rec(g?a+d:a,b-d,2*d,!f,n/2);
  
    
   
 }
    int lastRemaining(int n) {
       
    return rec(1,n,1,0,n);
    }
};

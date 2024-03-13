class Solution {
public:
    int pivotInteger(int n) {
     int a=0;
     int s=(n*(n+1))/2;
     int x=-1;
     for(int i=1;i<=n;i++){
    // cout<<s<<" "<<a<<endl;
     a+=i;
     if(a==(s-a+i)){
     x=i;break;}
         
     }
     return x;
    }
};
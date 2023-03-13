class Solution {
public:
    int findNthDigit(int n) {
        int m=n;
        int i=1;
        long long d=9; 
      if(n<9) return n;
       // int pt=0;
      while(n>(d*i)){
       n-=d*i;
        d=d*10;
          i++;
      }
        n--;
      int c=n/i,e=pow(10,i-1);
       // c--;
        e+=c;
      int r=n%i;
      int f=i-1; 
     // cout<<m<<" "<<n<<" "<<e<<endl;
      while(e){
        if(f==r){
           return e%10;
         }
        e/=10;
        f--;
      }
        return 0;
    }
};

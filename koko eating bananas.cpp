class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
     
     int i=1,r; 
   r=*max_element(piles.begin(),piles.end())+10;
      
    while(i<=r){
     int m=(i+r)/2;
        
     int j=h;
  for(int k=0;k<piles.size();k++){
     
   j-=ceil(double(piles[k]*1.0/m*1.0));
      
      }
   // cout<<m<<" "<<j<<endl;
    if(j>=0)
      r=m-1;
   else i=m+1;
    }
    return r+1;
    }
};

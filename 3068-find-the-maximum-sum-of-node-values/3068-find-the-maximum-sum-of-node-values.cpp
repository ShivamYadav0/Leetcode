class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans=0;
        int c=0;
        
        
      
      for(auto &x:nums){
       
        
          if((x^k)>x){
              c++;
              
              ans+=(x^k);
              
          }
          else {
              ans+=x;
            
           }
          
       
      }
      
        long long m1=0,m2=0;
      if(c&1){
         
       for(auto x:nums){
         if((x^k)>x)
         m1=max(m1,ans-(x^k)+x);
           else
         m2=max(m2,ans+(x^k)-x);
           
        }
      }
        else return ans;
      //  if(c==nums.size())
          //  return m1;
        return max(m1,m2);
    }
};
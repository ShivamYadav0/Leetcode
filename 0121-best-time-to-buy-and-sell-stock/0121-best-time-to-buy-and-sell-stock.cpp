class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int ans=0,mn=prices[0];
   for(auto x:prices){
    if(x>mn)
    ans=max(ans,x-mn);
    else 
    mn=x;
  }
     return ans;
  }
};
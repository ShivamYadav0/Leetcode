class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      
        int n=nums.size();
        int i=0,j=n-1;
        vector<int>dp(n);
          for(int k=n-1;k>-1;k--){
              if(abs(nums[i])>abs(nums[j])){
                  dp[k]=nums[i]*nums[i];
                  i++;
              }else{
                  dp[k]=nums[j]*nums[j];
                  j--;
              }
          }
        return dp;
    }
};
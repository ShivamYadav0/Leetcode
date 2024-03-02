class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
         int i=0,j=0;
        int n=nums.size();
        while(j<n&&nums[j]<0)j++;
        for(auto &x:nums)x=abs(x);
        vector<int>dp;
         i=j-1;
        while(i>=0&&j<n){
            if(nums[i]<=nums[j]){
                dp.push_back(nums[i]*nums[i]);
                i--;
            }
            else {
                dp.push_back(nums[j]*nums[j]);
                j++;
            }
        }
         while(i>=0){
            
                dp.push_back(nums[i]*nums[i]);
                i--;
            }
              while(j<n){
            
                dp.push_back(nums[j]*nums[j]);
                j++;
            } 
        return dp;
    }
};
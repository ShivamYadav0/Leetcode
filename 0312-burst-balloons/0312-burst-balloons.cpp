class Solution {
public:
    vector<vector<int>>dp;
    int rec (vector<int>&nums,int i,int j){
        if(i>j){
            //if(i==j)return nums[i];
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        for(int k=i+1;k<j;k++){
           ans=max(ans, rec(nums,i,k)+ nums[i]*nums[k]*nums[j]+rec(nums,k,j));
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        v.push_back(1);
        for(auto x:nums)v.push_back(x);
        v.push_back(1);
        dp.resize(n+2,vector<int>(n+2,-1));
        return rec(v,0,n+1);
    }
};
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i+=3){
            int j=i;
            if(nums[j+2]-nums[j]<=k){
           
                     ans.push_back({nums[j],nums[j+1],nums[j+2]});
                 
            }
            else 
                return {};
        }
        return ans;
    }
};
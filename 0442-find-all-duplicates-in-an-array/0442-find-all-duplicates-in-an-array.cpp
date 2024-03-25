class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        for(auto x:nums){
            nums[x%n]+=n;
        }
        vector<int>ans;
        for(int i=1;i<n;i++){
            if(nums[i]>2*n){
                ans.push_back(i);
            }
        }
        if(nums[0]>2*n){
            ans.push_back(n);
        }
        return ans;
    }
};
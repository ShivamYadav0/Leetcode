class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res = 0;
            
        int mini=-1, maxi=-1, left = -1;
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]<minK || nums[i] > maxK) {
                left = mini = maxi = i;
            } 
            mini = nums[i]==minK ? i : mini;
            maxi = nums[i]==maxK ? i : maxi;
            res += min(maxi, mini)-left;  
        }
        return res;
    }
};
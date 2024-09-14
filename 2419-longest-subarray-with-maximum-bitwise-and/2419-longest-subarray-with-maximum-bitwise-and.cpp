class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 1, maxNum = INT_MIN;
        for (int& i : nums)
            maxNum = max(i, maxNum);

        for (int i = 0; i < nums.size(); i++) {
            int maxFreq = 1;
            while (i < nums.size() - 1 && nums[i] == maxNum &&
                   nums[i] == nums[i + 1]) {
                maxFreq++;
                res = max(res, maxFreq);
                i++;
            }
        }
        return res;
    }
};
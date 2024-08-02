class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int c1 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                c1++;
        }
        for(int i=0;i<c1;i++){
            nums.push_back(nums[i]);
        }
        int i = 0;
        int j = i + c1;
        n+=c1;
        int zero_count = 0;
        for (int i = 0; i < c1; i++) {
            if (nums[i] == 0) {
                zero_count++;
            }
        }
        
        int min_swaps = zero_count;
        for (int i = c1; i < n; i++) {
            if (nums[i] == 0) {
                zero_count++;
            }
            if (nums[i - c1] == 0) {
                zero_count--;
            }
            min_swaps = min(min_swaps, zero_count);
        }
        return min_swaps;
    }
};
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for(const auto &a : nums){
            target |= a;
        }

        int output = countMaxOrSubsets(nums, target, 0);

        return output;
    }

    int countMaxOrSubsets(vector<int>& nums, int target, int first){
        int c = target == 0? 1: 0;
        if(first == nums.size() ){
            return c;
        }
        for(int i = first; i < nums.size(); i++){
            int new_target = target & (~nums[i]);
            c += countMaxOrSubsets (nums, new_target, i+1);
        }
        return c;
    }
};
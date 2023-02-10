class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int v=nums[0],c=1;
        for(int i=1;i<nums.size();i++){
            if(c==0)v=nums[i];
            if(nums[i]==v)c++;
            else if(c>0) c--;
            
        }
        return v;
    }
};
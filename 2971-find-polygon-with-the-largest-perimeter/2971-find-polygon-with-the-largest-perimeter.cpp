class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        long long cs=nums[0]+nums[1];
        long long mx=-1;
        int i=2,j=0;
        int n=nums.size();
        for(int i=2;i<n;i++){
            if(cs>nums[i]){
                mx=cs+(nums[i])*1ll;
            }
            cs+=nums[i];
        }
        return mx;
    }
};
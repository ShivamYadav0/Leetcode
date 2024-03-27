class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int s=1;
        int c=0;
        int j=0;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<nums.size();i++){
            j=max(j,i);
            while(j<n&&s*nums[j]<k){
               s*=nums[j];
               j++;
            }
            c=j-i;
            //cout<<i<<" - "<<j<<" "<<endl;
            ans+=max(0,c);
            if(s>=nums[i])
            s/=nums[i];
        }
        return ans;
    }
};
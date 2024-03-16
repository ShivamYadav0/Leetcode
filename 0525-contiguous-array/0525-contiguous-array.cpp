class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(auto &x:nums){
            if(x==0)x=-1;
        }
        unordered_map<int,int>mp;
        int ans=0;
        int s=0;
        mp[s]=-1;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(mp.find(s)!=mp.end()){
                ans=max(ans,i-mp[s]);
               // cout<<i<<" ";
            }
            else
            mp[s]=i;
        }
        return ans;
    }
};
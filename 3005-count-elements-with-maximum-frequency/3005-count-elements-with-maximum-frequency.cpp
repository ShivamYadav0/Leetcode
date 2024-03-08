class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int s=0;
        for(auto x: nums){
            mp[x]++;
            s=max(s,mp[x]);
            
         }
        int c=0;
        for(auto [x,y]:mp)
            if(y==s)c+=y;
        return c;
    }
};
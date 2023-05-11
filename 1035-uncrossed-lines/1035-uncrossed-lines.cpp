class Solution {
public:
     unordered_map<int,vector<int>>mp;
    vector<vector<int>>dp;
    int rec(vector<int>&v,int c,int i){
        if(i==v.size()||c==dp[0].size())return 0;
        if(dp[i][c+1]!=-1)
            return dp[i][c+1];
        int r=rec(v,c,i+1);
        if(mp.find(v[i])==mp.end())
            return dp[i][c+1]=r;
        auto it=upper_bound(mp[v[i]].begin(),mp[v[i]].end(),c);
        int mx=r;
        while(it!=mp[v[i]].end()){
            
            mx=max(rec(v,*it,i+1)+1,mx);
            it++;
        }
        return dp[i][c+1]=mx;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
       
       
        for(int i=0;i<nums2.size();i++){
           // mp[nums2[i]].first=0;
            mp[nums2[i]].push_back(i);
        }
        dp.resize(nums1.size()+5,vector<int>(nums2.size()+6,-1));
        return rec(nums1,-1,0);
    }
};
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int,int>mp;
        int mx=1;
      
        
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]-d]){
                mx=max(mx,mp[arr[i]-d]+1);
            }
            mp[arr[i]]=mp[arr[i]-d]+1;
        }
        return mx;
    }
};
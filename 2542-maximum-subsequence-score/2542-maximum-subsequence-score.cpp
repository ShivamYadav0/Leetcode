class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>v(nums1.size());
    for(int i=0;i<nums1.size();i++)
        v[i]={nums2[i],nums1[i]};
    sort(v.begin(),v.end());
        long long ans=0;
    multiset<int>ms;
        long long s=0;
     for(int i=nums1.size()-1;i>=0;i--){
        if(ms.size()<k){
            ms.insert(v[i].second);
            s+=v[i].second;
            }
        if(ms.size()==k) {
            
            ans=max(ans,(s*(long long)v[i].first));
            
            s-=*ms.begin();
            ms.erase(ms.begin());
         }
         
      }
        
        return ans;
    }
};
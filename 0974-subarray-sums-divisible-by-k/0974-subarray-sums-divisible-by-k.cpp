class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
 unordered_map<int,int>mp;
    long long s=0;
    int ans=0;
    mp[0]++;
   
   
   for(auto x:nums){
    s+=x;
    //cout<<s<<endl;
    int m=s%k;
    if(m<0)m+=k;
   // cout<<m<<endl;
    ans+=mp[m];
    mp[m]++;
   
   }
   
    return ans;
     
    }
};
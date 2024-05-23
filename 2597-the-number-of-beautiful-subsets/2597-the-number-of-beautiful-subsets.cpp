class Solution {
public:
   int k;
    int rec(vector<int>&v,int i, unordered_map<int,int>&mp){
        if(i==v.size()){
           
            return 0;
        }
        int ans=0;
       if( !mp[v[i]-k] ){
           mp[v[i]]++;
          
          ans+= rec(v,i+1,mp)+1;
           
           mp[v[i]]--;
       }
       
       ans+= rec(v,i+1,mp);
        return ans;
    }
    int beautifulSubsets(vector<int>& nums, int kn) {
        k=kn;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
       return rec(nums,0,mp);
    }
};


class Solution {
public:
    bool check(vector<int>v,int k,int m){
        
        for(int i=0;i<v.size();i++){
            if(v[i]<=m)k--,i++;
            if(k<=0)return 1;
        }
        return k<=0;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=*min_element(nums.begin(),nums.end());
        int r=*max_element(nums.begin(),nums.end());
        int m;
        while(l<=r){
            m=(l+r)/2;
            
            if(check(nums,k,m))
                r=m-1;
            else l=m+1;
        }
        return l;
    }
};

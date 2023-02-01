class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int s=1,mx=INT_MIN,p=1;
        for(int i=0;i<nums.size();i++){
            s*=nums[i];
            mx=max(mx,s);
            mx=max(mx,s/p);
            //cout<<p<<endl;
            if(s==0)s=1,p=1;
            
            else if(s<0&&p==1)p=s;
        }
        return mx;
    }
};
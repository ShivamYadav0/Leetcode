class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans;
        int dif=INT_MAX,t=0;
        int j,k;
        for(int i=0;i<n;i++){
            j=i+1,k=n-1;
            
            while(j<k){
                 t=nums[i]+nums[j]+nums[k];
                if(t>target){
                    if(dif>abs(target-t)){
                        ans.clear();
                        dif=abs(target-t);
                        
                        ans={nums[i],nums[j],nums[k]};
                    }
                    k--;
                }
                 else {
                    if(dif>abs(target-t)){
                        ans.clear();
                        dif=abs(target-t);
                      
                        ans={nums[i],nums[j],nums[k]};
                    }
                    j++;
                }
                if(dif==0)
                    break;
            }
            if(t==target)
                break;
        }
        return ans[0]+ans[2]+ans[1];
    }
};
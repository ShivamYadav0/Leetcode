class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
       
        int dif=INT_MAX,t=0;
        int j,k;
        for(int i=0;i<n-2;i++){
            j=i+1,k=n-1;
            
            while(j<k){
                 t=nums[i]+nums[j]+nums[k];
                if(t>target){
                    if(abs(dif)>abs(target-t)){
                       
                        dif=target-t;
                        
                        
                    }
                    k--;
                }
                 else {
                    if(abs(dif)>abs(target-t)){
                       
                        dif=target-t;
                      
                        
                    }
                    j++;
                }
                if(dif==0)
                    break;
            }
            if(t==target)
                break;
        }
        return target-dif;
    }
};
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int i=0,j=nums.size()-1;
        
        int m;
        while(i<=j){
            m=(i+j)/2;
            if(m%2){
                if(nums[m-1]==nums[m])
                i=m+1;
                else 
                    j=m-1;
            }
            else{
                 if(nums[m]==nums[m+1])
                i=m+1;
                else 
                    j=m-1;
                
            }
        }
        return nums[i];
    }
};
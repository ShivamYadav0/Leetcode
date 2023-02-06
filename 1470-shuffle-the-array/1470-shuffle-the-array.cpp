class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        int i=0,j=n,k=0;
        int  mx=1e3+1;
        while(i<2*n){
            
            if(i%2==0)nums[i]=(nums[k++]%mx)*mx+nums[i];
            else nums[i]=(nums[j++]%mx)*mx+nums[i];
            i++;
        }
        for(int i=0;i<2*n;i++)nums[i]/=mx;
        return nums;
    }
};
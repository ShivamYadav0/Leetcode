class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>v(2*n);
        int i=0,j=n,k=0;
        
        while(i<2*n){
            
            if(i%2==0)v[i]=nums[k++];
            else v[i]=nums[j++];
            i++;
        }
        return v;
    }
};
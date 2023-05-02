class Solution {
public:
    int arraySign(vector<int>& nums) {
        int c=0;bool f=0;
        for(auto &x:nums){
            if(x<0)c++;
            else if(x==0)
             return 0;
        }
        return c%2?-1:1;
    }
};
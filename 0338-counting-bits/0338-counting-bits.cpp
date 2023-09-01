class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int m=i,c=0;
            while(m>0){
                m=m&(m-1);
                c++;
                
            }
            ans.push_back(c);
        }
        return ans;
        
    }
};
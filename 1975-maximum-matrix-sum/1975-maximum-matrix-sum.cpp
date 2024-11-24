class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        long long s=0;
        long long mn=1e6;
        long long c=0;
        for(auto x:matrix){
            for(auto y:x){
                if(y<0)c++;
                if(abs(y)<mn){
                   // c++;
                    mn= abs(y);
                }
                s+=abs(y);
            }
        }
        if(c%2){
        s-=2*mn;
    }
    return s;
    }
   

};
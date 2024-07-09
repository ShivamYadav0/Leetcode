class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cus) {
        
        
        int i=0;
        int j=0;
        double ans=0.0;
        long long s=0;
        int t=cus[0][0];
        while(i<cus.size()){
            if(t<cus[i][0])t=cus[i][0];
            t+=cus[i][1];
            
            s+=t-cus[i][0];
            i++;
        }
        ans=s;
        ans=ans/(double)(cus.size());
        
        return ans;
    }
};
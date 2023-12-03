class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int ans=0;
        vector<int>p=points[0];
        for(auto x:points){
            ans+=max(abs(x[0]-p[0]),abs(x[1]-p[1]));
            p=x;
        }
        return ans;
    }
};
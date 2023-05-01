class Solution {
public:
    double average(vector<int>& s) {
        int mx=*max_element(s.begin(),s.end());
        int mn=*min_element(s.begin(),s.end());
        double sm=accumulate(s.begin(),s.end(),(double)0);
        sm-=mn+mx;
         return sm/double(s.size()-2);
    }
};
#define sort(a) sort(begin(a), end(a))
#define opt() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
class Solution {
public:
    int minGroups(vector<vector<int>>& il) {
        opt();
        
        vector<int> hm(1000002,0);
        for(auto ele:il) {
            hm[ele[0]]++;
                hm[ele[1]+1]--;
        }
        int ans=1;
        for(int i=1;i<=1000001;i++) {
            hm[i] = hm[i]+hm[i-1];
            ans = max(ans,hm[i]);
        }

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>>gr;
    int n, m;
    int dp[70][70][70][70];
    int dir[3][2] = {{1, 1}, {1, 0}, { 1, -1}};
    bool isValid(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m)return false;
        return true;
    }
    int rec(int i1, int j1, int i2, int j2) {

        if(dp[i1][j1][i2][j2]!=-1){
            return dp[i1][j1][i2][j2];
        }
        int vl = 0;
        if (i1 == i2 && j1 == j2) {
            vl = gr[i1][j1];
        }
        else {
            vl = gr[i1][j1] + gr[i2][j2];
        }
       
        int ans = 0;
        vector<int>calls={0};
        for (auto di1 : dir) {
            int ni1 = i1 + di1[0];
            int nj1 = j1 + di1[1];
            if (isValid(ni1, nj1)) {
                for (auto di2 : dir) {
                    int ni2 = i2 + di2[0];
                    int nj2 = j2 + di2[1];
                    if (isValid(ni2, nj2)) {
                        calls.push_back(rec(ni1, nj1, ni2, nj2));
                    }
                }

            }
        }
        for (auto x : calls) {
            ans = max(ans, x+vl);
        }
        return  dp[i1][j1][i2][j2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        gr = grid;
        n = gr.size();
        m = gr[0].size();
        memset(dp, -1, sizeof(dp));
        return  rec(0,0,0,m-1);
    }
};
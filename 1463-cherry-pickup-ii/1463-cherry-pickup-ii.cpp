class Solution {
public:

    int n, m;
    int dp[70][70][70];
    int dir[3][2] = {{1, 1}, {1, 0}, { 1, -1}};
    bool isValid(int x, int y) {
        if (y < 0 || x >= n || y >= m)return false;
        return true;
    }
    int rec(vector<vector<int>>&gr, int i, int j1, int j2) {

        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }
        int vl = 0;
        if (j1 == j2) {
            vl = gr[i][j1];
        }
        else {
            vl = gr[i][j1] + gr[i][j2];
        }

        int ans = vl;
      
        for (auto& di1 : dir) {
            int ni = i + 1;
            int nj1 = j1 + di1[1];
            if (isValid(ni, nj1)) {
                for (auto &di2 : dir) {

                    int nj2 = j2 + di2[1];
                    if (isValid(ni, nj2)) {
                        ans = max(ans, rec(gr, ni, nj1, nj2) + vl);
                    }
                }

            }
        }

        return  dp[i][j1][j2] = ans;
    }
    int cherryPickup(vector<vector<int>>& gr) {

        n = gr.size();
        m = gr[0].size();
        memset(dp, -1, sizeof(dp));
        return  rec(gr, 0, 0, m - 1);
    }
};
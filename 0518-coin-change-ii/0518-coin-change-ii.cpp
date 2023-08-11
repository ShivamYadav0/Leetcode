class Solution
{
    vector<vector < int>> dp;
    public:

        int rec(int i, int s, int t, vector<int> &v)
        {

            if (s >= t) return s == t;
            if (i == v.size()) return 0;
            if (dp[i][s] != -1)
                return dp[i][s];
            int ans = rec(i, s + v[i], t, v) + rec(i + 1, s, t, v);

            return dp[i][s]=ans;
        }
    int change(int amount, vector<int> &coins)
    {
        dp.resize(coins.size() + 1, vector<int> (amount + 1, -1));
        return rec(0, 0, amount, coins);
    }
};
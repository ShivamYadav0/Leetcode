class Solution
{
public:
    vector<int> dp;
    int rec( int mask, int c, vector<int> &v)
    {
        if (c == v.size()/2 +1)
            return 0;
        if (dp[mask] != -1)
            return dp[mask];
      
       int ans=0;
        for (int j = 0; j < v.size(); j++)
        {
            if(mask&(1<<j))
                continue;
            for (int k = 0; k < v.size() ;k++)
            {
                if (!(mask & (1 << k)) && k!=j)
                {
                  int  nm = mask | (1 << j);
                    nm |= (1 << k);
        ans = max(ans, rec( nm, c + 1, v) + c * (__gcd(v[j], v[k])));
                }
            }
        }
        return dp[mask] = ans;
    }
    int maxScore(vector<int> &nums)
    {
        dp.resize((1 << 16), -1);
        int mx = 0;
        mx = rec( 0, 1, nums);
        return mx;
    }
};
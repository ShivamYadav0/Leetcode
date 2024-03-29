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
      
      // int ans=0;
        for (int j = 0; j < v.size(); j++)
        {
            if(mask&(1<<j))
                continue;
            for (int k = j+1; k < v.size() ;k++)
            {
                if (!(mask & (1 << k)))
                {
                  int  nm = mask | (1 << j);
                    nm |= (1 << k);
                     dp[mask]=max( dp[mask],rec( nm, c + 1, v) + c * (__gcd(v[j], v[k])));
                  
                   // ans = max(ans,s);
                }
            }
        }
        return dp[mask] ;
    }
    int maxScore(vector<int> &nums)
    {
        dp.resize((1 << 14), -1);
        int mx = 0;
        mx = rec( 0, 1, nums);
        return mx;
    }
};
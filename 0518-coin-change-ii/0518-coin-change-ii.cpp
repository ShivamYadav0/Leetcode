class Solution
{

    public:

        int change(int amount, vector<int> &coins)
        {

            vector<int> dp(amount + 1, 0);
            dp[0] = 1;
            int ans = 0;
            for (int i = 0; i < coins.size(); i++)
            {
                for (int j = 1; j <= amount; j++)
                {
                    if (coins[i] <= j)
                    {
                        dp[j] += dp[j - coins[i]];
                    }
                }
            }
            return dp[amount];
        }
};
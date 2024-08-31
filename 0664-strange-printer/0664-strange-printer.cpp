class Solution {
public:
    int strangePrinter(string s) {
        int len = s.size();

        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));

        int ans, tmp, right;

        for (int left = len - 1; left >= 0; left--)

        {

            dp[left][left] = 1;

            for (int right = left + 1; right < len; right++)

            {

                ans = INT_MAX;

                for (int k = left; k < right; k++)

                {

                    tmp = dp[left][k] + dp[k + 1][right];

                    ans = min(ans, tmp);

                }

                if (s[left] == s[right])

                    ans--;

                dp[left][right] = ans;

            }

        }

        return dp[0][len - 1];
    }
};
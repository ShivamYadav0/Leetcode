class Solution {
public:
    void optimizeIO() {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
    }

    int width;
    int sol(int i, int height, vector<vector<int>>& books, int w,
            vector<vector<int>>& dp) {
        int n = books.size();
        if (i == n) {

            return height;
        }
        if (dp[i][w] != -1)
            return dp[i][w];
        int same = INT_MAX;
        if (w - books[i][0] >= 0) {
            same = sol(i + 1, max(height, books[i][1]), books, w - books[i][0],
                       dp);
        }

        int nsame =
            height + sol(i + 1, books[i][1], books, width - books[i][0], dp);

        return dp[i][w] = min(same, nsame);
    }

    int minHeightShelves(vector<vector<int>>& books, int w) {
        optimizeIO();
        int n = books.size();
        if (books.empty())
            return 0;
        width = w;
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
        return sol(1, books[0][1], books, w - books[0][0], dp);
    }
};
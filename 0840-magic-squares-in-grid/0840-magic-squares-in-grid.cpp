class Solution {
public:
    void solve(int row, int col, int &ans, unordered_map<int, int> mp, vector<vector<int>>& grid) {
        int row1Sum = 0, row2Sum = 0, row3Sum = 0;
        int col1Sum = 0, col2Sum = 0, col3Sum = 0;
        int diagonal1Sum = 0, diagonal2Sum = 0;

        // Ensure that you are within the grid bounds
        if (row - 1 >= 0 && col >= 0 && col < grid[0].size() && mp[grid[row-1][col]]) {
            mp.erase(grid[row-1][col]);
            row1Sum += grid[row-1][col];
            col2Sum += grid[row-1][col];
        }

        if (row - 1 >= 0 && col - 1 >= 0 && mp[grid[row-1][col-1]]) {
            mp.erase(grid[row-1][col-1]);
            row1Sum += grid[row-1][col-1];
            col1Sum += grid[row-1][col-1];
            diagonal1Sum += grid[row-1][col-1];
        }

        if (row - 1 >= 0 && col + 1 < grid[0].size() && mp[grid[row-1][col+1]]) {
            mp.erase(grid[row-1][col+1]);
            row1Sum += grid[row-1][col+1];
            col3Sum += grid[row-1][col+1];
            diagonal2Sum += grid[row-1][col+1];
        }

        if (col - 1 >= 0 && mp[grid[row][col-1]]) {
            mp.erase(grid[row][col-1]);
            row2Sum += grid[row][col-1];
            col1Sum += grid[row][col-1];
        }

        if (col + 1 < grid[0].size() && mp[grid[row][col+1]]) {
            mp.erase(grid[row][col+1]);
            row2Sum += grid[row][col+1];
            col3Sum += grid[row][col+1];
        }

        if (mp[grid[row][col]]) {
            mp.erase(grid[row][col]);
            row2Sum += grid[row][col];
            col2Sum += grid[row][col];
            diagonal1Sum += grid[row][col];
            diagonal2Sum += grid[row][col];
        }

        if (row + 1 < grid.size() && col - 1 >= 0 && mp[grid[row+1][col-1]]) {
            mp.erase(grid[row+1][col-1]);
            row3Sum += grid[row+1][col-1];
            col1Sum += grid[row+1][col-1];
            diagonal2Sum += grid[row+1][col-1];
        }

        if (row + 1 < grid.size() && mp[grid[row+1][col]]) {
            mp.erase(grid[row+1][col]);
            row3Sum += grid[row+1][col];
            col2Sum += grid[row+1][col];
        }

        if (row + 1 < grid.size() && col + 1 < grid[0].size() && mp[grid[row+1][col+1]]) {
            mp.erase(grid[row+1][col+1]);
            row3Sum += grid[row+1][col+1];
            col3Sum += grid[row+1][col+1];
            diagonal1Sum += grid[row+1][col+1];
        }

        if (row1Sum == row2Sum && row2Sum == row3Sum &&
            row1Sum == col1Sum && col1Sum == col2Sum &&
            col2Sum == col3Sum && col3Sum == diagonal1Sum &&
            diagonal1Sum == diagonal2Sum && diagonal1Sum == 15) {
            ans++;
        }
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 1; i <= 9; i++) {
            mp[i]++;
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i > 0 && j > 0) {
                   
                    solve(i, j, ans, mp, grid);
                }
            }
        }
        return ans;
    }
};
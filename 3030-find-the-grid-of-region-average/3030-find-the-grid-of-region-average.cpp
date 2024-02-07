class Solution {
public:
    vector<vector<int>>  regionSum, regionCount;
    int limit = 3;
    int thres;
    bool handler(int i, int j, vector<vector<int>>&image) {
        bool check = true;

        for (int k = 0; k < limit ; k++) {
            for (int l = 1; l < limit ; l++) {
                if (abs(image[i + k][j + l] - image[i + k][j + l - 1]) > thres) {
                    check = false;
                }
            }
        }

        for (int k = 1; k < limit; k++) {
            for (int l = 0; l < limit ; l++) {
                if (abs(image[i + k][j + l] - image[i + k - 1][j + l]) > thres) {
                    check = false;
                }
            }
        }

        return check;
    }
    void sumAndUpdate(int i, int j, vector<vector<int>>&image) {
        int sum = 0;
        for (int k = 0; k < limit ; k++) {
            for (int l = 0; l < limit ; l++) {
                sum += image[i + k][j + l];
            }
        }
        for (int k = 0; k < limit ; k++) {
            for (int l = 0; l < limit; l++) {

                regionCount[i + k][j + l]++;
                regionSum[i + k][j + l] = (regionSum[i + k][j + l] + sum / 9);
            }
        }
    }
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size();
        int m = image[0].size();
        thres = threshold;
        regionSum.resize(n, vector<int>(m, 0));
        regionCount.resize(n, vector<int>(m, 0));

        for (int i = 0; i <= n - limit; i++) {
            for (int j = 0; j <= m - limit; j++) {

                if (handler(i, j, image)) {
                    sumAndUpdate(i, j, image);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (regionCount[i][j] == 0)
                    regionSum[i][j] = image[i][j];

                else
                    regionSum[i][j] = (regionSum[i][j]) / regionCount[i][j];
            }
        }

        return regionSum;
    }
};
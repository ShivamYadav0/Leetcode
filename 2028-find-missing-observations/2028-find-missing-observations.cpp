class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total_sum = mean * (n + m);
        int sum_m = accumulate(rolls.begin(), rolls.end(), 0);
        int sum_n = total_sum - sum_m;
        
        if (sum_n < n || sum_n > 6 * n) {
            return {};
        }
        
        vector<int> result(n, sum_n / n);
        int remainder = sum_n % n;
        
        for (int i = 0; i < remainder; ++i) {
            result[i]++;
        }
        
        return result;
    }
};
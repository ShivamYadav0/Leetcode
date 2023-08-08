class Solution {
public:
    int maxIncreasingGroups(vector<int>& A) {
        int n = A.size();
        unordered_map<int, int> count;
        for (int a : A)
            count[min(a, n)]++;
        long long total = 0, k = 0;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < count[i]; j++)
                if ((total += i) >= (k + 1) * (k + 2) / 2)
                    k++;
        return k;
    }
};
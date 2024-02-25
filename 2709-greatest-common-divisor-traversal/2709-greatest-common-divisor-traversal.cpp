// <editor-fold defaultstate="collapsed" desc="#define OUT(...)">
#ifndef OUT
#define OUT(...)
#endif
// </editor-fold>

const int N = 1e5 + 10;
//const int N = 400;
int min_factor[N];

const auto prime_count = [] {
    vector<int> v;
    v.reserve(9593);
    for (int i = 2; i < N; ++i) {
        if (!min_factor[i]) min_factor[i] = i, v.push_back(i);
        for (int x: v) {
            int y = x * i;
            if (y >= N) break;
            min_factor[y] = x;
            if (i % x == 0) break;
        }
    }
    return v.size();
}();

const vector<int> &split(int x) {
    static vector<int> v;
    v.clear();
    while (x > 1) {
        int y = min_factor[x];
        v.push_back(y);
        while ((x /= y) % y == 0);
    }
    return v;
}

int father[N];

class DisjointSet {
public:
    explicit DisjointSet(int n) {
        memset(father, -1, n * sizeof father[0]);
    }

    int getf(int x) { // NOLINT(misc-no-recursion)
        int &y = father[x];
        if (y < 0) return x;
        return y = getf(y);
    }

    bool merge(int x, int y) {
        x = getf(x), y = getf(y);
        if (x == y) return false;
        father[x] = y;
        return true;
    }
};

class Solution {
public:
    static bool canTraverseAllPairs(const vector<int> &nums) {
        int n = (int) nums.size();
        if (n < 2) return true;
        vector<int> mp(1 + *max_element(nums.begin(), nums.end()));
        DisjointSet ds(n);
        int c = 1;
        for (int i = 0; i < n; ++i) {
            for (int x: split(nums[i])) {
                int &u = mp[x];
                if (!u) u = i + 1;
                else if (ds.merge(u - 1, i)) ++c;
            }
        }
        return c == n;
    }
};
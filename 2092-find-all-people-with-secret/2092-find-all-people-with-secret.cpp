struct node {
    int v, w;
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int fp) {
        vector<vector<node>>g(n);
        for (auto x : meetings) {
            g[x[0]].push_back({x[1], x[2]});
            g[x[1]].push_back({x[0], x[2]});
        }
        queue<node>q;
        int lim = INT_MAX;
        vector<int>dis(n, lim);
        dis[0] = 0;
        dis[fp] = 0;
        q.push({0, 0});
        q.push({fp, 0});
        while (!q.empty()) {
            auto c = q.front();
            q.pop();

            for (auto &x : g[c.v]) {
                if (x.w >= c.w && dis[x.v] > x.w) {
                    q.push({x.v, x.w});
                    dis[x.v] = x.w;
                }
            }
        }
        vector<int>v;
      
        for (int i=0;i<n;i++) {
            if (dis[i] != lim)
                v.push_back(i);
          
        }
        return v;
    }
};
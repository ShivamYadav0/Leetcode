struct Air {
    int st;
    int w;
    int n;
    Air(int a, int b, int c) {
        n = c, st = a, w = b;
    }
};
class Compare {
public:
    bool operator()(Air &a, Air &b) {

        if (a.w > b.w) return 0;
        if (a.w == b.w)
            return a.st > b.st;

        return 1;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>g[n];
        for (auto x : flights) {
            g[x[0]].push_back({x[1], x[2]});

        }
        priority_queue<Air, vector<Air>, Compare>pq;
        // Air a= Air(0,0,src);
        pq.push({0, 0, src});
        vector<int>vis(n, 1e5);

        vis[src] = 0;
        int ans = INT_MAX;
        while (!pq.empty()) {

            Air node = pq.top();
            pq.pop();
            // cout<<node.n<<endl;

            // if(node.n!=dst&&node.st>k)
            // continue;
            if (node.n == dst && node.st <= k + 1) {

                ans = min(ans, node.w);
            }


            for (auto x : g[node.n]) {
                if (x.first == dst && node.st <= k) {

                    //cout<<node.w<<endl;
                    ans = min(ans, node.w + x.second);

                }
                if (x.second + node.w < vis[x.first]) {
                    vis[x.first] = x.second + node.w;
                    //cout<<x.first<<endl;
                    Air b = Air(node.st + 1, node.w + x.second, x.first);
                    pq.push(b);
                    //cout<<b.n<<endl;
                }
            }
        }
        if (ans != INT_MAX) return ans;
        return -1;
    }
};
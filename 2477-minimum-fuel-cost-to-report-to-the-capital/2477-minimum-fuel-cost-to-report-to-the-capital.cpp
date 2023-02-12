class Solution {
public:
    long long  ans=0;
    long long rec(vector<int>graph[],int u,int prev,int seats){
    
       int people = 1;
    for (const int v : graph[u]) {
      if (v == prev)
        continue;
      people += rec(graph, v, u, seats);
    }
    if (u > 0)
      // # of cars needed = ceil(people / seats)
      ans += (people + seats - 1) / seats;
    return people;
        

    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<int>g[n];
        for(auto x:roads){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        rec(g,0,-1,seats);
        return ans;
    }
};
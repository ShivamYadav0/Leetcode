class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
         vector<bool> visited(n, false);

        for(auto i:edges)
        {
            visited[i[1]] = true;
        }

        vector<int> ans;
        for(int i=0; i<size(visited); i++)
        {
            if(visited[i] == false)
                ans.push_back(i);
        }
        return ans;
    }
};
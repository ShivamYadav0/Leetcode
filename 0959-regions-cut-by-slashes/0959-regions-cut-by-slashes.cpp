class Solution {
public:
    int n,m;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool isvalid(int x,int y)
    {
        return x>=0 && x<n && y>=0 && y<m;
    }
    void dfs(vector<vector<int>>&adj,vector<vector<bool>>&visited,int i,int j)
    {
        visited[i][j]=true;
        for(auto dir:directions)
        {
            int i_=i+dir[0];
            int j_=j+dir[1];
            if(isvalid(i_,j_) && !visited[i_][j_] && adj[i_][j_]==0)
            {
                dfs(adj,visited,i_,j_);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        n=grid.size()*3;
         m=grid[0].size()*3;
        vector<vector<int>>adj(n,vector<int>(m,0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='/')
                {
                    adj[i*3][j*3+2]=1;
                    adj[i*3+1][j*3+1]=1;
                    adj[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\')
                {
                    adj[i*3][j*3]=1;
                    adj[i*3+1][j*3+1]=1;
                    adj[i*3+2][j*3+2]=1;
                }
            }
        }
        int region=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(adj[i][j]==0 && !visited[i][j])
                {
                    dfs(adj,visited,i,j);
                    region++;
                }
            }
        }
        return region;

    }
};
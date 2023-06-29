class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        int count=0;
        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};
        queue<vector<int>> q;   // {i,j,steps,curr_key_status}
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@'){
                    q.push({i,j,0,0});
                }
                else if(grid[i][j]>='a' && grid[i][j]<='f') count++;  // key count
            }
        }
        int final_state=(1<<count)-1;   // 2^count-1
        int vis[n][m][final_state+1];
        memset(vis,0,sizeof(vis));
        while(!q.empty()){
            auto  temp=q.front();
            q.pop();
            int r=temp[0];
            int c=temp[1];
            int steps=temp[2];
            int curr_state=temp[3];
            if(curr_state==final_state) return steps;
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!='#'){
                    char c=grid[nr][nc];
                    if(c>='a' && c<='f'){   // key encountered
                        int new_state=curr_state | (1<<(c-'a'));   // changing key status
                        if(!vis[nr][nc][new_state]){
                            vis[nr][nc][new_state]=1;
                            q.push({nr,nc,steps+1,new_state});
                        }
                    }
                    else if(c>='A' && c<='Z'){  // lock encountered
                        if(!vis[nr][nc][curr_state] && (curr_state & (1<<(c-'A')))){   // checking if the key collected for the given lock
                            vis[nr][nc][curr_state]=1;
                            q.push({nr,nc,steps+1,curr_state});
                        }
                    }
                    else if(!vis[nr][nc][curr_state]){   // empty cell
                        vis[nr][nc][curr_state]=1;
                        q.push({nr,nc,steps+1,curr_state});
                    }
                }
            }
        }
        return -1;
    }
};
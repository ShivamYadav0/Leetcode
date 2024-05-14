class Solution {
public:
    int mx=0;
    bool isValid(vector<vector<int>>& g,int i,int j){
        if(i<0||i>=g.size()||j<0||j>=g[0].size()) return 0;
      
        return g[i][j]!=0;
    }
    int rec(vector<vector<int>>& g,int i ,int j,int s=0){
        
        int p=g[i][j];
       // s+=p;
       // mx=max(mx,s);
        g[i][j]=0;
        
        
        int arr[]={1,-1,0,0};
        int arr1[]={0,0,1,-1};
        bool f=0;
        for(int k=0;k<4;k++){
            if(isValid(g,i+arr[k],j+arr1[k])){
                f=1;
                rec(g,i+arr[k],j+arr1[k],s+g[i+arr[k]][j+arr1[k]]);
            }
        }
        if(!f){
            mx=max(mx,s);
        }
     
        g[i][j]=p;
        
        return s;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(isValid(grid,i,j))
                rec(grid,i,j,grid[i][j]);
            }
        }
        return mx;
    }
};
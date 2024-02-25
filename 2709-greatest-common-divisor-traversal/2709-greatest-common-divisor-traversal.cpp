class Solution {
public:
    unordered_map<int,vector<int>>mp1;
    unordered_map<int,vector<int>>mp2;
    unordered_map<int,int>vis1;
    unordered_map<int,int>vis2;
    void dfs(int id,bool flag){
        
       vis1[id]=1;
        for(auto x:mp1[id]){
            if(vis2[x]>0)continue;
            vis2[x]=1;
            for(auto y:mp2[x]){
                if(vis1[y]>0)continue;
                dfs(y,flag);
            }
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        if(nums.size()==1)return true;
        if(nums[0]==1)return false;
        for(int j=0;j<n;j++){
            //if(mp[])
            int x=nums[j];
            //if(mp2[x].size()>0)continue;
            for(int i=2;i*i<=x;i++){  
                if(x%i==0){
                    
                    mp1[j].push_back(i);
                    mp2[i].push_back(j);
                    while(x>1&&x%i==0)x/=i;
                   
                }
            }
            if(x>1){
                 mp2[x].push_back(j);
                 mp1[j].push_back(x);
            }
        }
    
        int src=nums[n-1];
        dfs(0,0);
        bool flag=1;
        int i=0;
        for(auto x:nums){
            if(vis1[i++]>0){ 
            }
            else 
            flag=0;
        }
        
        return flag;
    }
};
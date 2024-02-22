class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        
        unordered_map<int,unordered_set<int>>mp;
        unordered_map<int,unordered_set<int>>np;
        for(auto x:trust){
            mp[x[0]].insert(x[1]);
            np[x[1]].insert(x[0]);
        }
        for(int i=1;i<=n;i++){
            if(np[i].size()==n-1 && mp[i].size()==0){
                return i;
            }
        }
        return -1;
    }
};
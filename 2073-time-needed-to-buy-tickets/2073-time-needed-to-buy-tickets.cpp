class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int s=0;
        queue<pair<int,int>>q;
        int i=0;
        for(auto x:tickets){
           if(x==0&&i==k) return 0;
            q.push({x,i++});
        }
        while(!q.empty()){
            pair <int,int>p=q.front();
            s++;
            q.pop();
            if(p.first==1&&p.second==k){
                return s;
            }
            if(p.first>1){
                q.push({p.first-1,p.second});
            }
        }
        return 0;
    }
};
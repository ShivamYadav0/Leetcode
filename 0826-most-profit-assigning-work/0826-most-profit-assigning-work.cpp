class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>v;
         v.resize(profit.size());
        
        for(int i=0;i<profit.size();i++){
            v[i]={difficulty[i],profit[i]};
        }
        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());
        
        int ans=0;
        int mx=0;
        int i=0;
        for(int j=0;j<worker.size();j++){
            while(i<v.size()&&worker[j]>=v[i].first){
              
                mx=max(mx,v[i].second);
                  i++;
            }
            //cout<<mx<<endl;
            ans+=mx;
        }
        return ans;
    }
};
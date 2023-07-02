class Solution {
public:
    int ans=0;
     vector<int>in;
        vector<int>out;
   
void rec(vector<vector<int>>&v,int i,int c){
        if(i==v.size()){
            bool f=1;
            for(int j=0;j<in.size();j++){
                if(in[j]!=out[j]) 
                    f=0;
            }
           // cout<<f<<" ";
            if(f)
                ans=max(ans,c);
            return ;
        }
        in[v[i][1]]++;
        out[v[i][0]]++;
            
        rec(v,i+1,c+1);
     in[v[i][1]]--;
        out[v[i][0]]--;
            rec(v,i+1,c);
            
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
       in.resize(n,0);
        out.resize(n,0);
      
         rec(requests,0,0);
        return ans;
    }
};
class Solution {
public:
    vector<int>bit;
    void update(int id , int vl){
        for(int i=id;i<bit.size();i+=(i&(-i))){
            bit[i]+=vl;
        }
    }
    int query(int id ){
        int s=0;
        for(int i=id;i>0;i-=(i&(-i))){
            s+=bit[i];
        }
        return s;
    }
    vector<int> processQueries(vector<int>& queries, int m) {
        bit.resize(2*m+1,0);
        int n=m;
        for(int i=1;i<=n;i++)
            update(i,1);
        unordered_map<int,int>mp;
        for(int i=1;i<=m;i++)
            mp[i]=n+i;
        //int c=4;
        //cout<<mp[c]-query(n+c)-1;
        vector<int>ans;
        for(auto x:queries){
            int t=mp[x];
            int id=t-query(t)-1;
            update(t,1);
            mp[x]=n;
            update(n,-1);
            n--;
            ans.push_back(id);
        }
        return ans;
    }
};
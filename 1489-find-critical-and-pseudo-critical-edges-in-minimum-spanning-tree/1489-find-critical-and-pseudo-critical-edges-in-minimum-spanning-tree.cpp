class Solution {
public:
    //ya to edge ko lo yaa to naa lo
    //iss edge ko leke dekho  ki ktna aarha mst ka
    int parent[101]={0};
    int rank[101]={0};
    int dsu_parent(int i){
        if(i==parent[i])return i;
        else return parent[i]=dsu_parent(parent[i]);
    }
    void dsu_union(int i,int j){
        i=dsu_parent(i);
        j=dsu_parent(j);
        if(i!=j){
            if(rank[i]>=rank[j]){
                parent[j]=i;
                rank[i]+=rank[j];
                rank[j]=0;
            }
            else{
                parent[i]=j;
                rank[j]+=rank[i];
                rank[i]=0;
            }
        }
    }
    
    int include(int n, vector<vector<int>> &edges,vector<int>edge){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
        int ans=edge[2];
        if(dsu_parent(edge[0])!=dsu_parent(edge[1]))dsu_union(edge[0],edge[1]);
        for(auto v:edges){
            if(dsu_parent(v[0])!=dsu_parent(v[1])){
                ans+=v[2];
                dsu_union(v[0],v[1]);
            }
        }
        return ans;
    }
    
    int not_include(int n, vector<vector<int>> &edges,int ind){
       for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
       int ans=0;

        for(int i=0;i<edges.size();i++){
            vector<int>v=edges[i];
            if(i==ind)continue;
            else{
                if(dsu_parent(v[0])!=dsu_parent(v[1])){
                    ans+=v[2];
                    dsu_union(v[0],v[1]);
                }
            }
        }
        if( (edges.size()==0  and ind==0)  or  (rank[dsu_parent(edges[0][0])] <n))return 1e9;
        return ans;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        //intersection of all msts
        //union of all msts

        //jinko remove karne se wt badh jaata hai wo critical
        //jo kuch mst me hai baaki me nhi non critical

        //how will you find union of all msts?????
        //inko chodh ke mst ban jaarha hai to non critcal
        map<vector<int>,int>edge_ind;
        for(int i=0;i<edges.size();i++){
            edge_ind[edges[i]]=i;
        }
        sort(edges.begin(),edges.end(),[](vector<int>v1,vector<int>v2){
            return v1[2]<v2[2];
        });
        vector<vector<int>>ans(2);
        int mst=include(n,edges,{0,0,0});
        //includ
        for(int i=0;i<edges.size();i++){
            vector<int>v=edges[i];
            if(not_include(n,edges,i)>mst){
                ans[0].push_back(edge_ind[v]);
            }
            else if(include(n,edges,v)==mst){
                ans[1].push_back(edge_ind[v]);
            }
        }
        return ans;

    }
};
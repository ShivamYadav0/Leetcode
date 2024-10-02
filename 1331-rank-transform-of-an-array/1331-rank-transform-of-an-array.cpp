struct customComparator{
    bool operator()(const int& a,const int& b)const{
        return a>b;
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int pq[100001]={0};
        int pqIndex=0;
        unordered_map<int,int>mp;
        for(int& i:arr){
           pq[pqIndex++]=i;
           
        }
        make_heap(pq,pq+pqIndex,customComparator());
        int rnk=1;
        int sz=arr.size();
        vector<int>res(sz,0);
        while(pqIndex){
            int top=pq[0];
            pop_heap(pq,pq+pqIndex,customComparator());
            pqIndex--;
            if(mp.find(top)==mp.end()){
                mp[top]=rnk++;
            }
        }
        int idx=0;
        for(int i:arr){
           res[idx++]=mp[i];
        }
        return res;
    }
};
static const int KDS=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;

}();
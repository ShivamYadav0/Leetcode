class Solution {
public:
    int furthestBuilding(vector<int>& h, int br, int la) {
        
        priority_queue<long long>pq;
        int ans=0;
        long long s=0;
        for(int i=1;i<h.size();i++){
            if(h[i]>h[i-1]){
                s+=h[i]-h[i-1];
                if(la>0)
                pq.push(h[i]-h[i-1]);
            }
           
            while(s>br&&!pq.empty()&&la>0){
                s-=pq.top();
                pq.pop();
                la--;
                
            }
            if(s>br){
                break;
            }
             if(s<=br){
                ans=i;
            }
            
        }
        return ans;
    }
};
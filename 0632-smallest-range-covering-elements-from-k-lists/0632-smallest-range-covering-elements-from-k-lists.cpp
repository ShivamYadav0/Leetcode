class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int maxx=INT_MIN;
        int ran=INT_MAX;
        vector<int> index;
        vector<int> range;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],i});
            maxx=max(maxx,nums[i][0]);
            index.push_back(0);
        }
        
        while(pq.empty()==false){
            if(ran>(maxx-pq.top().first)){
                ran=abs(maxx-pq.top().first);
                range={pq.top().first,maxx};
                cout<<maxx<<" "<<pq.top().first<<endl;
            }
            pair<int,int> top=pq.top();
            pq.pop();
            index[top.second]++;

            if(index[top.second]<nums[top.second].size()){
                int num=nums[top.second][index[top.second]];
                if(maxx<num)
                {
                    maxx=num;
                }
                pq.push({num,top.second});
            }
            else{
                break;
            }
        }

        return range;
    }
};
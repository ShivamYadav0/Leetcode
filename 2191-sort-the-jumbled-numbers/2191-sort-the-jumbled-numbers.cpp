class Solution {
public:


    bool static comp(pair<int, pair<int, int>>a, pair<int, pair<int, int>>b){
        if(a.first<b.first) return 1;
        else if(a.first==b.first) return a.second.second<b.second.second;
        return 0;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, pair<int, int>>>v;

        int n=nums.size();

        for(int i=0; i<n; i++){
            stack<int>st;
            int t=0;
            int tmp=nums[i];
            while(tmp){
                st.push(mapping[tmp%10]);
                tmp/=10;
            }
            if(nums[i]==0){
                st.push(mapping[0]);
            }
            while(!st.empty()){
                t=(t*10)+(st.top());
                st.pop();
            }
            v.push_back({t, {nums[i], i}});
        }

        sort(v.begin(), v.end(), comp);

        vector<int>ans;

        for(auto &it:v){
            ans.push_back(it.second.first);
        }

        return ans;        
    }
};
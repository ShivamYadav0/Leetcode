class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>> temp;
        vector<string> ans;
        for(int i=0;i<names.size();i++){
            temp.push_back({names[i],heights[i]});
        }

        sort(temp.begin(),temp.end(),[](auto& a,auto& b){
            return a.second>b.second;
        });

        for(auto t:temp){
            ans.push_back(t.first);
        }
        return ans;
    }
};
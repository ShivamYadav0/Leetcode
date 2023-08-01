class Solution {
public:
   vector<vector<int>> ans;
    void recur(int ind, int n, int k, vector<int> &temp)
    {
        if(k == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(ind == n + 1)return;

        //take
        temp.push_back(ind);
        recur(ind + 1, n , k - 1, temp);
        temp.pop_back();
        //not take
        recur(ind + 1, n, k, temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        recur(1, n, k, temp);
        return ans;
    }
};
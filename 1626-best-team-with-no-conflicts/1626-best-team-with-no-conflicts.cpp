class Solution {
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages){
    //this question is kinda similar to longest increasing subsequence
    //here we have to find maximum sum non decreasing subsequence instead of length of longest increasing subsequence
    vector<pair<int, int>> v(ages.size());
    for (int i = 0; i < ages.size(); i++)
        v[i] = {ages[i], scores[i]};
    //here we sort the array according to height
    sort(v.begin(), v.end());
    int ans = 0;
    vector<int> dp(ages.size() + 1, 0);
    for (int i = 0; i < v.size(); i++)
    {

        int mx = 0;
        for (int j = i - 1; j >= 0; j--)
        {

            if (v[i].second >= v[j].second)
                mx = max(mx, dp[j]);
        }
        // we will add the maximum sum 
        dp[i] += mx + v[i].second;
    }
    for (auto x : dp)
        ans = max(ans, x);

    
    return ans;
  }
};
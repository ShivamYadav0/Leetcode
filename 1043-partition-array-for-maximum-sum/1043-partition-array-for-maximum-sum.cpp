class Solution {
public:

    vector<int>dpp;
    int rec(vector<int>&arr, int i, int k) {
        //base case if we have covered whole array so return 0 ;
        if (i == arr.size()) {
//Note:- we are returning 0 not the calculated sum as we are already doing that in recursive call.
            return 0;
        }
        //returning memoised value
        if (dpp[i] != -1)return dpp[i];
        // ans variable to keep track of max state among all
        int ans = 0;

        //mx variable to store the max element of subsegment
        int mx = arr[i];
        // traversing from i to i+k as we can have at most k elements in subsegment
        // so we will try to find max sum among all state i.e from index i to min(i+k,arr.size()-1)
        for (int j = i; j < arr.size() && j < i + k; j++) {
            //keeping track of max element
            mx = max(mx, arr[j]);
            //calculating current segment answer by adding mx (j-i+1) times i.e for each state and then adding answer from segment j+1 as current ends at j.
            int l = (j - i + 1) * mx + rec(arr, j + 1, k);

            //finding max among all states
            ans = max(ans, l);
        }
        //storing answer and returning it
        return dpp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        //initialising dp
        dpp.resize(arr.size() + 1, -1);
        //calling rec function
        return rec(arr, 0, k);
    }
};
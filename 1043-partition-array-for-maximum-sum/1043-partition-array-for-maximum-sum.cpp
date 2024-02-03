class Solution {
public:

    vector<int>dpp;
    int solve_rec(vector<int>&arr, int curr_ind, int at_most_lengthK) {
        //base case if we have covered whole array so return 0 ;
        if (curr_ind == arr.size()) {
//Note:- we are returning 0 not the calculated sum as we are already doing that in recursive call.
            return 0;
        }
        //returning memoised value
        if (dpp[curr_ind] != -1)return dpp[curr_ind];
        // ans variable to keep track of max state among all
        int ans = 0;

        //max_el variable to store the max element of subsegment
        int max_el = arr[curr_ind];
        // traversing from i to i+k as we can have at most k elements in subsegment
        // so we will try to find max sum among all state i.e from index curr_ind to min(curr_ind+k,arr.size()-1)
        for (int j = curr_ind; j < arr.size() && j < curr_ind + at_most_lengthK; j++) {
            //keeping track of max element
            max_el = max(max_el, arr[j]);
            //calculating current segment answer by adding max_el (j-i+1) times i.e for each state and then adding answer from segment j+1 as current ends at j.
            int curr_state_ans = (j - curr_ind + 1) * max_el + solve_rec(arr, j + 1, at_most_lengthK);

            //finding max among all states
            ans = max(ans, curr_state_ans);
        }
        //storing answer and returning it
        return dpp[curr_ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        //initialising dp
        dpp.resize(arr.size() + 1, -1);
        //calling rec function
        return solve_rec(arr, 0, k);
    }
};
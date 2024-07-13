class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        vector <vector <int>> v;

        for(int i = 0; i < directions.size(); i++) {

            // v[i][0] = positions[i];
            // v[i][1] = healths[i];
            // v[i][2] = 'L' == directions[i] ? 0: 1;

            v.push_back({positions[i], healths[i], 'L' == directions[i] ? 0: 1});
        }

        sort(v.begin(), v.end());

        vector <vector <int>> stk;

        for(int i = 0; i < v.size(); i++) {

            if(!stk.empty() and stk.back()[2] == 1 and v[i][2] == 0) {
                if(stk.back()[1] > v[i][1]) {
                    stk.back()[1]--;
                }

                else if(stk.back()[1] < v[i][1]) {

                        stk.pop_back();
                        v[i][1]--;
                        i--;
                }

                else {
                    stk.pop_back();
                }
            }

            else {
                stk.push_back(v[i]);
            }
        }


        unordered_map <int, int> m;

        for(int i = 0; i < stk.size(); i++) {

            m[stk[i][0]] = stk[i][1];
        }

        vector <int> res;

        for(int i = 0; i < positions.size(); i++) {

            if(m[positions[i]] != 0) {
                res.push_back(m[positions[i]]);
            }
        }

        return res;
    }
};
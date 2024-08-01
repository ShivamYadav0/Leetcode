class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(long long i=0;i<details.size();i++){
            if((details[i][11]-'0'==6&&details[i][12]-'0'>=1)||(details[i][11]-'0'>6)){
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if(n == 2) return skill[0]*skill[1];

        sort(skill.begin() , skill.end());
        
        bool cond = true;
        int value = skill[0] + skill[n-1];
        for(int i = 0 ; i < n ; i++){
            if( (skill[i] + skill[n-i-1]) != value  ) cond = false;
        }

        long long ans = 0;
        if(cond){
            for(long long i = 0 ; i < n/2 ; i++){
                ans += skill[i] *skill[n-i-1];
            }
        }
        else{
            return -1;
        }
            

        return ans;


    }
};
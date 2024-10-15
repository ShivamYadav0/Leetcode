class Solution {
public:
    long long minimumSteps(string s) {
        long long len = s.length();
        long count =0, swap =0;
        for(int i =0; i<len; i++)
        {
            if(s[i] == '1')
            {
                count++;
            }
            else
            {
                swap += count;
            }
        }
    return swap;

    }
};
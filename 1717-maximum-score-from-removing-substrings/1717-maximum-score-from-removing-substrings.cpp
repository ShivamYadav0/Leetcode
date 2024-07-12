class Solution {
public:

    void solve(string &s, string ref, int &gain, int num){
        string st = "";
        const int m = s.size();
        for(int i=0;i<m;++i){
            if(s[i]==ref[1] && !st.empty() && st.back()==ref[0]){gain+=num;st.pop_back();}else{st.push_back(s[i]);}
        }
        s = st;
    }

    int maximumGain(string s, int x, int y) {
        int gain = 0;
        string main = s;
        string ref;
        int maxGain = max(x,y);
        int minGain = min(x,y);
        if(x>y){ref="ab";}else{ref="ba";}
        solve(s,ref,gain,maxGain);
        reverse(ref.begin(),ref.end());
        solve(s,ref,gain,minGain);        
        return gain;
    }
};
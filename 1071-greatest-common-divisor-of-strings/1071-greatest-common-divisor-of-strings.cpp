class Solution {
public:
    string gcdOfStrings(string s, string t) {
        if(s+t!=t+s)return "";
        int g=__gcd(s.length(),t.length());
        return s.substr(0,g);
    }
};
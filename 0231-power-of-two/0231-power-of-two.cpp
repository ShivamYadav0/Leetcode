class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(INT_MIN==n)return false;
        return n&&!(n&(n-1));
    }
};
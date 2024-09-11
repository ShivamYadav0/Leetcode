class Solution {
public:
    int minBitFlips(int s, int g) {
        int count=0;
        while(s>0 or g>0){
            if((s&1)!=(g&1)) count++;
            s=s>>1;
            g=g>>1;
        }
    return count;
    }
};
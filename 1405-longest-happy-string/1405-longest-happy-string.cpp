class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        ios_base::sync_with_stdio(0);
        int cnt_a = 0, cnt_b = 0, cnt_c = 0, i = a+b+c;
        string str;
        while (i>0) {
            if ((cnt_c == 2 && a == 0 && b == 0) ||
                (cnt_b == 2 && c == 0 && a == 0) ||
                (cnt_a == 2 && c == 0 && b == 0) ||
                (a == 0 && b == 0 && c == 0))
                break;
            i--;
            if (a >= b && a >= c && cnt_a < 2) {
                str += 'a';
                a--;
                cnt_a++;
                cnt_b = 0;
                cnt_c = 0;
                continue;
            } else if (cnt_a == 2) {
                if (b > c) {
                    str += 'b';
                    b--;
                    cnt_b++;
                    cnt_a = 0;
                    cnt_c = 0;
                } else {
                    str += 'c';
                    c--;
                    cnt_c++;
                    cnt_a = 0;
                    cnt_b = 0;
                    continue;
                }
            }
            if (b >= a && b >= c && cnt_b < 2) {
                str += 'b';
                b--;
                cnt_b++;
                cnt_a = 0;
                cnt_c = 0;
                continue;
            } else if (cnt_b == 2) {
                if (a > c) {
                    str += 'a';
                    a--;
                    cnt_a++;
                    cnt_b = 0;
                    cnt_c = 0;
                } else {
                    str += 'c';
                    c--;
                    cnt_c++;
                    cnt_a = 0;
                    cnt_b = 0;
                }
                continue;
            }
            if (c >= a && c >= b && cnt_c < 2) {
                str += 'c';
                c--;
                cnt_c++;
                cnt_a = 0;
                cnt_b = 0;
                continue;
            } else if (cnt_c == 2) {
                if (b > a) {
                    str += 'b';
                    b--;
                    cnt_b++;
                    cnt_a = 0;
                    cnt_c = 0;
                } else {
                    str += 'a';
                    a--;
                    cnt_c = 0;
                    cnt_a++;
                    cnt_b = 0;
                }
                continue;
            }
        }
        return str;
    }
};
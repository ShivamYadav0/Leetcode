class Solution {
  public:

    int minimumSwap(string s1, string s2) {
      int x1 = 0, x2 = 0;
      for (auto x: s1) x1 += (x == 'x');
      for (auto x: s2) x2 += (x == 'x');

      int count = 0;
      if ((x1 + x2)&1) return -1;
      for (int i = 0; i < s1.length(); i++) {
        int indexToSwap = -1;
        
        if (s1[i] != s2[i]) {
          for (int j = i + 1; j < s1.length(); j++) {
            if (s1[i] == s1[j]) {
              indexToSwap = j;
              if (s1[j] != s2[j]) break;
            }

          }
          if (indexToSwap == -1) {
            swap(s1[i], s2[i]);
            i--;
          } else
            swap(s2[i], s1[indexToSwap]);
          count++;

        }
      }
      return count;

    }

};
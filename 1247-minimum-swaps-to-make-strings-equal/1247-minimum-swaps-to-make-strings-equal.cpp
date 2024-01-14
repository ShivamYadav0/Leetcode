class Solution {
  public:

    int minimumSwap(string s1, string s2) {
      int x1 = 0, x2 = 0;
      for (auto x: s1) x1 += (x == 'x');
      for (auto x: s2) x2 += (x == 'x');

      int count = 0;
      if ((x1 + x2)&1) return -1;
      int countXNotEqual=0,countYNotEqual=0;
        
      for (int i = 0; i < s1.length(); i++) {
           if (s1[i] != s2[i]) {
               countXNotEqual+=(s1[i]=='x');
               countYNotEqual+=(s1[i]=='y');
           }
      }
       return countXNotEqual/2 + countYNotEqual/2 + countXNotEqual%2 + countYNotEqual%2;
     

    }

};
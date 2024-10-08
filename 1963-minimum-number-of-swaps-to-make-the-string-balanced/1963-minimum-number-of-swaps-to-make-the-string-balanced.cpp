class Solution {
public:
    int minSwaps(string s) {
        // Initialize two pointers: 'l' starting from the left, 'r' from the right
        int l = 0, r = s.size() - 1;
        
        // 'cnt' will keep track of imbalance between '[' and ']'
        // 'ans' will count the number of swaps performed
        int cnt = 0, ans = 0;

        // Traverse the string using the two pointers
        while (l < r) {
            // If current character at 'l' is '[', increase the balance count
            if (s[l] == '[') {
                cnt++;
            }
            // If current character at 'l' is ']', decrease the balance count
            else {
                cnt--;
            }

            // If the balance is negative (more ']' than '[' at this point), we need a swap
            while (cnt < 0 && l < r) {
                // Look for the first '[' from the right to correct the imbalance
                if (s[r] == '[') {
                    // Increase the balance by 2 since we're swapping a '[' with a ']'
                    cnt += 2;
                    // Increment the swap count
                    ans++;
                    // Perform the swap: set 's[l]' to '[' and 's[r]' to ']'
                    s[r] = ']';
                    s[l] = '[';
                }
                // Move the right pointer to continue the search for a '['
                r--;
            }
            // Move the left pointer to the next character
            l++;
        }

        // Return the total number of swaps performed to balance the string
        return ans;
    }
};
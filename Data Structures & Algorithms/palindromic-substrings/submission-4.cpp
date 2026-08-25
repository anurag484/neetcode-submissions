class Solution {
public:
    void expandAroundCenter(string& s, int left, int right, int& count) {
        int n = s.length();
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;  // Found a palindrome
            left--;   // Expand left
            right++;  // Expand right
        }
    }

    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            // Count odd-length palindromes centered at i
            expandAroundCenter(s, i, i, count);

            // Count even-length palindromes centered between i and i+1
            expandAroundCenter(s, i, i + 1, count);
        }
        return count;
    }
};

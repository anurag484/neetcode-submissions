class Solution {
public:
    // Function to expand around center and return start and length of palindrome
    void expandAroundCenter(string s, int left, int right, int& bestStart, int& maxLen) {
        int n = s.length();
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        left++; // Move back to the last valid position
        right--; // Move back to the last valid position

        int length = right - left + 1;
        if (length > maxLen) {
            bestStart = left;
            maxLen = length;
        }
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s; // If the string has 0 or 1 characters, return it immediately.

        int start = 0, maxLen = 0;

        for (int i = 0; i < n; i++) {
            // Check for odd-length palindrome (centered at i)
            expandAroundCenter(s, i, i, start, maxLen);

            // Check for even-length palindrome (centered between i and i+1)
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }
};

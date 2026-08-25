class Solution {
public:
    vector<vector<int>> dp; // Memoization table

    bool isPalindrome(string& s, int i, int j) {
        if (i >= j) return true; // Base case: single character or empty string is a palindrome
        if (dp[i][j] != -1) return dp[i][j]; // Return if already computed

        if (s[i] == s[j]) {
            return dp[i][j] = isPalindrome(s, i + 1, j - 1);
        }
        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        dp.assign(n, vector<int>(n, -1)); // Initialize DP table with -1
        
        int maxLen = 0, startIdx = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        startIdx = i;
                    }
                }
            }
        }
        return s.substr(startIdx, maxLen);
    }
};

class Solution {
public:
    bool solve(int i, int j, string &text, string &pattern, vector<vector<int>> &dp) {
        int n = text.size();
        int m = pattern.size();

        // Base cases
        if (i == n && j == m) return true;   // Both exhausted
        if (j == m) return false;            // Pattern exhausted but text remains

        if (dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        // If next character in pattern is '*' → handle separately
        if (j + 1 < m && pattern[j + 1] == '*') {
            // Case 1: skip "x*" in pattern
            ans = solve(i, j + 2, text, pattern, dp);

            // Case 2: if current matches, consume one char of text and stay on same pattern
            if (i < n && (text[i] == pattern[j] || pattern[j] == '.')) {
                ans = ans || solve(i + 1, j, text, pattern, dp);
            }
        }
        else {
            // Normal case: characters match or pattern[j] = '.'
            if (i < n && (text[i] == pattern[j] || pattern[j] == '.')) {
                ans = solve(i + 1, j + 1, text, pattern, dp);
            }
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, s, p, dp);
    }
};

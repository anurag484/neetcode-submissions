class Solution {
public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>>& dp) {
        // If we have matched the entire t string
        if (j == t.size()) return 1;

        // If we've reached end of s but t still remains
        if (i == s.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int ways = 0;

        // If characters match, we have 2 choices:
        // 1. Take this character (move both i and j)
        // 2. Skip this character in s (move only i)
        if (s[i] == t[j]) {
            ways = solve(i + 1, j + 1, s, t, dp) + solve(i + 1, j, s, t, dp);
        } else {
            // If not match, we can only skip s[i]
            ways = solve(i + 1, j, s, t, dp);
        }

        return dp[i][j] = ways;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, s, t, dp);
    }
};

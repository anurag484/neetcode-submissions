class Solution {
public:
    int solve(int i, int j, const string &text1, const string &text2, vector<vector<int>>& dp) {
        int n = text1.size();
        int m = text2.size();

        // Base case: reached end of either string
        if (i == n || j == m) {
            return 0;
        }

        // Memoization check
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // If characters match
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1, text1, text2, dp);
        }

        // If they don't match
        return dp[i][j] = max(solve(i + 1, j, text1, text2, dp),
                              solve(i, j + 1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, text1, text2, dp); // ✅ Start from the front
    }
};

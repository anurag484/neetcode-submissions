class Solution {
public:
    bool solve(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>>& dp) {
        if (i == s1.length() && j == s2.length() && k == s3.length()) {
            return true;
        }
        if (k == s3.length()) {
            return false;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        bool useS1 = false, useS2 = false;

        if (i < s1.length() && s1[i] == s3[k]) {
            useS1 = solve(i + 1, j, k + 1, s1, s2, s3, dp);
        }
        if (j < s2.length() && s2[j] == s3[k]) {
            useS2 = solve(i, j + 1, k + 1, s1, s2, s3, dp);
        }

        return dp[i][j] = (useS1 || useS2);
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false; // Early exit if lengths don't match
        }
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};

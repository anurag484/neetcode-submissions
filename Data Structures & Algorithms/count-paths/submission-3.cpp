class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp) {
        // Base Case: If we reach (0,0), there's exactly one way to reach it
        if (i == 0 && j == 0) {
            return 1;
        }
        // Out of bounds check (prevents segmentation fault)
        if (i < 0 || j < 0) {
            return 0;
        }
        // Memoization check
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // Recursive calls to move up and left
        int up = solve(i - 1, j, dp);
        int left = solve(i, j - 1, dp);
        
        return dp[i][j] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp);
    }
};

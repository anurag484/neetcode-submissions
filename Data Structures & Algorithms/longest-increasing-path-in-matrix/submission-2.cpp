class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();

        if (dp[i][j] != -1) return dp[i][j];  // Return cached result

        int ans = 1;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int ind = 0; ind < 4; ind++) {
            int new_i = i + dx[ind];
            int new_j = j + dy[ind];

            if (new_i >= 0 && new_j >= 0 && new_i < n && new_j < m && matrix[i][j] < matrix[new_i][new_j]) {
                ans = max(ans, 1 + dfs(new_i, new_j, matrix, dp));
            }
        }
        return dp[i][j] = ans;  // Store result in dp
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));  // Memoization table

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxi = max(maxi, dfs(i, j, matrix, dp));
            }
        }
        return maxi;
    }
};

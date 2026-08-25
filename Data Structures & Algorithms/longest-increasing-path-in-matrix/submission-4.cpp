class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];  // already computed

        int n = matrix.size();
        int m = matrix[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        int maxPath = 1;  // at least the cell itself

        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && matrix[nx][ny] > matrix[i][j]) {
                maxPath = max(maxPath, 1 + dfs(nx, ny, matrix, dp));
            }
        }

        return dp[i][j] = maxPath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int longest = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                longest = max(longest, dfs(i, j, matrix, dp));
            }
        }

        return longest;
    }
};

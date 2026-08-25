class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int dx[] = {-1, 0, 1, 0};  // Directions: Up, Right, Down, Left
        int dy[] = {0, 1, 0, -1};

        int maxPath = 1;  // Every cell is at least a path of length 1

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];

            // Check if the new cell is within bounds and has a strictly larger value
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && matrix[ni][nj] > matrix[i][j]) {
                maxPath = max(maxPath, 1 + dfs(ni, nj, matrix));
            }
        }

        return maxPath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int longestPath = 0;

        // Start DFS from every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                longestPath = max(longestPath, dfs(i, j, matrix));
            }
        }

        return longestPath;
    }
};

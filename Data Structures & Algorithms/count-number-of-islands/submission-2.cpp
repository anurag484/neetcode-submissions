class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();

        // Base case: out of bounds, water, or already visited
        if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == '0' || visited[row][col])
            return;

        visited[row][col] = 1; // mark current cell as visited

        // Arrays for moving in 4 directions: up, right, down, left
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int newRow = row + dRow[k];
            int newCol = col + dCol[k];
            dfs(newRow, newCol, grid, visited);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        int count = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return count;
    }
};

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Base case: out of bounds or water ('0') or already visited
        if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == '0' || visited[row][col]) 
            return;
        
        // Mark the cell as visited
        visited[row][col] = 1;

        // Recursive DFS in all 4 directions
        dfs(row - 1, col, visited, grid); // Up
        dfs(row + 1, col, visited, grid); // Down
        dfs(row, col - 1, visited, grid); // Left
        dfs(row, col + 1, visited, grid); // Right
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == '1' && !visited[row][col]) {
                    count++;  // Found a new island
                    dfs(row, col, visited, grid);
                }
            }
        }
        return count;
    }
};

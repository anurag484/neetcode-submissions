class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int curr_row = q.front().first;
            int curr_col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int n_row = curr_row + del_row[i];
                int n_col = curr_col + del_col[i];
                if (n_row >= 0 && n_col >= 0 && n_row < n && n_col < m && grid[n_row][n_col] == '1' && !visited[n_row][n_col]) {
                    visited[n_row][n_col] = 1;
                    q.push({n_row, n_col});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == '1' && !visited[row][col]) {
                    count++;
                    bfs(row, col, visited, grid);
                }
            }
        }
        return count;
    }
};

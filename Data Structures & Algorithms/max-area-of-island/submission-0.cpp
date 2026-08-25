class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int count = 0;
        q.push({i, j});
        visited[i][j] = 1;
        count = 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int ind = 0; ind < 4; ind++) {
                int newi = x + dx[ind];
                int newj = y + dy[ind];
                
                if (newi >= 0 && newi < n && newj >= 0 && newj < m && 
                    !visited[newi][newj] && grid[newi][newj] == 1) {
                    q.push({newi, newj});
                    visited[newi][newj] = 1;
                    count++;
                }
            }
        }
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int area = bfs(grid, i, j, visited);
                    ans = max(ans, area);  // Update the maximum area found so far
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        int freshCount = 0;
        
        // Initialize the queue with all initially rotten oranges and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        // Perform BFS
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            time = max(time, t);
            
            for (int ind = 0; ind < 4; ind++) {
                int nrow = row + drow[ind];
                int ncol = col + dcol[ind];
                
                // If adjacent cell is a fresh orange, rot it
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1) {
                    grid[nrow][ncol] = 2;
                    freshCount--;
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }
        
        // If there are still fresh oranges, return -1
        return freshCount == 0 ? time : -1;
    }
};

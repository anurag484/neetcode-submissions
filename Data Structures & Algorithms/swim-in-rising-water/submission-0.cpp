class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Min-heap: stores {elevation, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // Visited matrix
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        // Start from (0,0)
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;
        
        int res = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while (!pq.empty()) {
            auto curr = pq.top(); 
            pq.pop();
            
            int elevation = curr[0];
            int x = curr[1];
            int y = curr[2];
            
            res = max(res, elevation);
            
            if (x == n-1 && y == n-1) return res; // reached destination
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }
        
        return -1; // should never happen
    }
};
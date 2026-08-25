class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // Min-heap (priority queue): stores {time, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Start at (0,0) with its elevation
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];

        // Directions
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int t = cur[0], r = cur[1], c = cur[2];

            // If we reached destination, return time
            if (r == n - 1 && c == n - 1) return t;

            // Explore neighbors
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newTime = max(t, grid[nr][nc]);
                    if (newTime < dist[nr][nc]) {
                        dist[nr][nc] = newTime;
                        pq.push({newTime, nr, nc});
                    }
                }
            }
        }

        return -1; // Should never reach here
    }
};
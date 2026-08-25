class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false); // Track visited points
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; // Min-Heap

        // Start from the first point (0th index)
        pq.push({0, 0}); // {cost, node}
        int totalCost = 0, edgesUsed = 0;

        while (edgesUsed < n) {
            int cost=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if (visited[node]) continue; // Skip if already in MST
            visited[node] = true;
            totalCost += cost;
            edgesUsed++;

            // Add all valid edges from current point
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int distance = abs(points[node][0] - points[v][0]) + abs(points[node][1] - points[v][1]);
                    pq.push({distance, v});
                }
            }
        }

        return totalCost;
    }
};
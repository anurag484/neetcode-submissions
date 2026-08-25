class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false); // Track visited points
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // Min-Heap

        // Start from the first point (0th index)
        minHeap.push({0, 0}); // {cost, node}
        int totalCost = 0, edgesUsed = 0;

        while (edgesUsed < n) {
            auto [cost, u] = minHeap.top();
            minHeap.pop();

            if (visited[u]) continue; // Skip if already in MST
            visited[u] = true;
            totalCost += cost;
            edgesUsed++;

            // Add all valid edges from current point
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int distance = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minHeap.push({distance, v});
                }
            }
        }

        return totalCost;
    }
};
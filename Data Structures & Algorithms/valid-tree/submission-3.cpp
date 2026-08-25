class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for (int nei : adj[node]) {
            if (!visited[nei]) {
                dfs(nei, adj, visited);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // A tree must have exactly n - 1 edges
        if (edges.size() != n - 1) return false;

        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // DFS to check connectivity
        vector<int> visited(n, 0);
        dfs(0, adj, visited);

        // Ensure all nodes are visited (graph is connected)
        for (int v : visited) {
            if (!v) return false;
        }
        return true;
    }
};

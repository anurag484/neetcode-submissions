class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Step 1: A valid tree must have exactly n-1 edges
        if (edges.size() != n - 1) {
            return false;
        }

        // Step 2: Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Step 3: DFS to check connectivity
        vector<int> visited(n, 0);
        dfs(0, -1, adj, visited);

        // Step 4: Check if all nodes were visited
        for (int v : visited) {
            if (v == 0) return false; // disconnected
        }
        return true; // connected + no cycle (because edges = n-1 ensures no cycle if connected)
    }

private:
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for (int nei : adj[node]) {
            if (!visited[nei]) {
                dfs(nei, node, adj, visited);
            } 
        }
    }
};

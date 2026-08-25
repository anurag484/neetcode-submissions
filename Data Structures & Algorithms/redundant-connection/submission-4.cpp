class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (dfs(it, node, adj, visited)) {
                    return true; // cycle found
                }
            } 
            else if (it != parent) {
                return true; // visited node that isn’t the parent → cycle
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto it : edges) {
            // add edge temporarily
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

            vector<int> visited(n + 1, 0);

            // check if cycle formed
            if (dfs(it[0], -1, adj, visited)) {
                return {it[0], it[1]}; // redundant edge
            }
        }
        return {};
    }
};

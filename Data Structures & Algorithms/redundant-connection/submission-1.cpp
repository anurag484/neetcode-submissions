class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            if (hasCycleUsingBFS(u, adj, n)) {
                return {u, v};
            }
        }
        return {};
    }

private:
   bool hasCycleUsingBFS(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visit(n + 1, false);
    queue<pair<int, int>> q; // (current node, parent node)

    q.push({start, -1});
    visit[start] = true;

    while (!q.empty()) {
        auto [node, parent] = q.front();
        q.pop();

        for (int nei : adj[node]) {
            if (nei == parent) {
                // Skip the parent node
                continue;
            }
            if (visit[nei]) {
                // A cycle is found if a visited neighbor is not the parent
                return true;
            }
            visit[nei] = true;
            q.push({nei, node});
        }
    }
    return false;
}

};

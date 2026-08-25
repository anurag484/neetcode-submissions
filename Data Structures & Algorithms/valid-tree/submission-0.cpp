class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // If there are more than n-1 edges, it cannot be a valid tree
        if (edges.size() != n - 1) {
            return false;
        }
        
        // Create adjacency list for the graph
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);  // add reverse direction for undirected graph
        }

        // Set to keep track of visited nodes
        unordered_set<int> visit;
        queue<pair<int, int>> q;
        q.push({0, -1});  // Start BFS from node 0, with no parent (-1)
        visit.insert(0);

        // Perform BFS to check for cycles and connectivity
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // Visit all the neighbors of the current node
            for (auto it : adj[node]) {
                // Skip the parent to avoid revisiting the node we came from
                if (it == parent) {
                    continue;
                }
                // If the neighbor has already been visited, return false (cycle detected)
                if (visit.count(it)) {
                    return false;
                }
                visit.insert(it);  // Mark the neighbor as visited
                q.push({it, node});  // Push the neighbor with the current node as its parent
            }
        }

        // If all nodes have been visited, the graph is connected and has no cycle
        return visit.size() == n;
    }
};

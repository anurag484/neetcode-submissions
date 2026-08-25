class Solution {
public:
    void dfs(string src, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj, vector<string>& result) {
        while (!adj[src].empty()) {
            string next = adj[src].top();
            adj[src].pop();
            dfs(next, adj, result);
        }
        result.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        
        // Build adjacency list (Min Heap to get lexicographically smallest airport first)
        for (auto& it : tickets) {
            adj[it[0]].push(it[1]);
        }

        vector<string> result;
        dfs("JFK", adj, result);

        // Reverse the result to get the correct order
        reverse(result.begin(), result.end());
        return result;
    }
};

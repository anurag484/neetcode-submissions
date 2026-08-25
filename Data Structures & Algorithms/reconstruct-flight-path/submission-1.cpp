class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;

    void dfs(string airport) {
        while (!adj[airport].empty()) {
            string next = adj[airport].top();
            adj[airport].pop();
            dfs(next);
        }
        result.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Step 1: Build the graph
        for (auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);  // Min-heap ensures lexicographical order
        }

        // Step 2: Start DFS from "JFK"
        dfs("JFK");

        // Step 3: Reverse the result to get the correct order
        reverse(result.begin(), result.end());
        return result;
    }
};


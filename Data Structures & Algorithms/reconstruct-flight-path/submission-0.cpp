
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;

        // Step 1: Build the adjacency list (min-heap ensures lexicographically smallest order)
        for (auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);  // Corrected from push_back() to push()
        }

        vector<string> result;
        stack<string> st;
        st.push("JFK");

        // Step 2: Perform iterative DFS with a stack
        while (!st.empty()) {
            string src = st.top();
            
            if (!adj[src].empty()) {
                string next = adj[src].top();
                adj[src].pop();  // Remove used edge
                st.push(next);
            } else {
                result.push_back(src);
                st.pop();
            }
        }

        // Step 3: Reverse the result to get the correct itinerary order
        reverse(result.begin(), result.end());
        return result;
    }
};


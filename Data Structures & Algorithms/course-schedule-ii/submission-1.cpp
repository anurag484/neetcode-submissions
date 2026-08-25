class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        // Construct adjacency list and in-degree array
        for (auto it : prerequisites) {
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }

        queue<int> q;
        // Push courses with no prerequisites into the queue
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // Decrease in-degree of neighboring courses
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If we processed all courses, return the order
        if (ans.size() == numCourses) {
            return ans;
        } else {
            return {}; // Return an empty array if it's impossible to finish all courses
        }
    }
};

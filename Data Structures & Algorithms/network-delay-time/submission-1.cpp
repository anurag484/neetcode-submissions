class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create an adjacency list to represent the graph.
        // adj[u] will store vectors of {v, time} for edges u -> v.
        vector<vector<int>> adj[n + 1];
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int t = time[2];
            adj[u].push_back({v, t});
        }

        // 'dist' array to store the shortest time from k to each node.
        // Initialize all distances to a large value (infinity).
        vector<int> dist(n + 1, 1e9);

        // A min-priority queue to store {time, node}.
        // It helps in always picking the node with the minimum current distance.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Start from the source node k.
        // The distance to itself is 0.
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // If we've found a shorter path to this node already, skip.
            if (time > dist[node]) {
                continue;
            }

            // Explore all neighbors of the current node.
            for (const auto& neighbor : adj[node]) {
                int adjNode = neighbor[0];
                int edgeWeight = neighbor[1];

                // If the path through the current node is shorter, update the distance.
                if (dist[node] + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // Find the maximum time among all nodes.
        // Start from index 1 since nodes are 1-based.
        int max_time = 0;
        for (int i = 1; i <= n; ++i) {
            // If any node is unreachable, its distance will be infinity.
            if (dist[i] == 1e9) {
                return -1;
            }
            max_time = max(max_time, dist[i]);
        }

        return max_time;
    }
};
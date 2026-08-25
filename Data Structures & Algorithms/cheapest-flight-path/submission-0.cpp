class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // adjacency list: each node has a list of {neighbor, price}
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            int from = it[0];
            int to = it[1];
            int price = it[2];
            adj[from].push_back({to, price});
        }

        // distance array
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // queue stores {stops, {node, cost}}
        queue<pair<int,pair<int,int>>> q;
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node  = it.second.first;
            int cost  = it.second.second;

            if(stops > k) continue;

            for(auto e : adj[node]){
                int adjNode = e.first;
                int edW     = e.second;

                if(cost + edW < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + edW;
                    q.push({stops+1, {adjNode, cost+edW}});
                }
            }
        }

        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};

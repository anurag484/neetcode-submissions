class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // Min-heap: {cost, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        vector<int> visited(n, 0);  
        int totalCost = 0, edgesUsed = 0;
        
        pq.push({0, 0}); // start with node 0
        
        while(edgesUsed < n) {
            auto [cost, node] = pq.top();
            pq.pop();
            
            if(visited[node]) continue; // already included
            
            visited[node] = 1;
            totalCost += cost;
            edgesUsed++;
            
            // Push all edges from this node to others
            for(int i=0; i<n; i++) {
                if(!visited[i]) {
                    int dist = abs(points[node][0] - points[i][0]) 
                             + abs(points[node][1] - points[i][1]);
                    pq.push({dist, i});
                }
            }
        }
        
        return totalCost;
    }
};
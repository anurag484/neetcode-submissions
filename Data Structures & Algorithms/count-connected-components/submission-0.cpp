class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& vis) {
        vis[node] = 1;  // Mark node as visited
        for (auto it : adjList[node]) {  // Iterate through all the neighbors
            if (!vis[it]) {  // If neighbor is not visited
                dfs(it, adjList, vis);  // Call DFS recursively
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) { 
        vector<vector<int>> adjList(n);  // Create adjacency list (vector of vectors)
        
        // Build the adjacency list from the edge list
        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);  // Since the graph is undirected
        }
        
        vector<int> vis(n, 0);  // Visited array, initialize all to 0
        int count = 0;  // To count the number of components
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {  // If the node is not visited
                count++;  // New component found
                dfs(i, adjList, vis);  // Call DFS to mark all nodes in this component
            }
        }
        
        return count;  // Return the number of components
    }
};

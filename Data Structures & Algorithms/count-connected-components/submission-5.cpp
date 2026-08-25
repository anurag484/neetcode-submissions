class Solution {
public:
    void dfs(int node,vector<int>& visited,vector<vector<int>>& adj){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adj);
            }
        }
        return count;
    }
};

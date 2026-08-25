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
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};

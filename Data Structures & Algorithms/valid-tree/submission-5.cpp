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
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1){
            return false;
        }
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(n,0);
        dfs(0,visited,adj);

        for(auto it:visited){
            if(!it){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& visited){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfs(it,node,adj,visited)){
                    return true;
                }
            }else if(it!=parent){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            vector<int>visited(n+1,0);
            if(dfs(u,-1,adj,visited)){
                return {u,v};
            }
        }
        return {};
    }
};

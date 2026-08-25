class Solution {
public:
    void bfs(int node,vector<int>& visited,vector<vector<int>>& adj){
        queue<int>q;
        q.push(node);
        visited[node]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                bfs(i,visited,adj);
            }
        }
        return count;
    }
};

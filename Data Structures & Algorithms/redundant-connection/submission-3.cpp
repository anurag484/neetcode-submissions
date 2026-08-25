class Solution {
public:
    bool isCycle(int start,vector<vector<int>>& adj,int n){
        vector<int>visited(n+1);
        queue<pair<int,int>>q;
        q.push({start,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(it==parent){
                    continue;
                }
                if(visited[it]){
                    return true;
                }
                visited[it]=true;
                q.push({it,node});
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

            if(isCycle(it[0],adj,n)){
                return {it[0],it[1]};
            }
        }
        return {};
    }
};

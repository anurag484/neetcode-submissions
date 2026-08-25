class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1){
            return false;
        }
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        unordered_set<int>visit;
        queue<pair<int,int>>q;
        q.push({0,-1});
        visit.insert(0);

        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();

            for(auto it:adj[node]){
                if(it==parent){
                    continue;
                }
                if(visit.count(it)){
                    return false;
                }
                visit.insert(it);
                q.push({it,node});
            }
        }
        return visit.size()==n;
    }
};

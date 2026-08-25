class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);

        for(auto it:prerequisites){
            int a=it[0];
            int b=it[1];
            indegree[a]++;
            adj[b].push_back(a);
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int finish=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            finish++;
            for(auto nei:adj[node]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
        }
        return finish==numCourses;
    }
};

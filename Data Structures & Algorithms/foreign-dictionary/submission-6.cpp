class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>>adj(26);
        vector<int>present(26,0);
        vector<int>indegree(26,0);

        for(auto w:words){
            for(auto ch:w){
                present[ch-'a']=1;
            }
        }

        for(int i=0;i+1<words.size();i++){
            string a=words[i];
            string b=words[i+1];

            int len=min(a.size(),b.size());
            int j=0;
            while(j<len && a[j]==b[j]){
                j++;
            }
            if(j==len){
                if(a.size()>b.size()){
                    return "";
                }
                continue;
            }

            int u=a[j]-'a';
            int v=b[j]-'a';
            bool exists=false;
            for(auto nei:adj[u]){
                if(nei==v){
                    exists=true;
                    break;
                }
            }
            if(!exists){
                adj[u].push_back(v);
                indegree[v]++;
            }
        }

        queue<int>q;
        for(int i=0;i<26;i++){
            if(present[i] && indegree[i]==0){
                q.push(i);
            }
        }

        string order;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            order.push_back(char('a'+u));
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        int total=0;
        for(int i=0;i<26;i++){
            if(present[i]){
                total++;
            }
        }
        if(order.size()!=total){
            return "";
        }

        return order;
    }
};

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
       for (const auto& w : words) {
    for (char c : w) {
        if (!adj.count(c)) {  // If character is not already in the map
            adj[c] = {};  // Initialize adjacency list
            indegree[c] = 0;  // Initialize in-degree to 0
        }
    }
}

        
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && 
                w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }
        
        queue<char> q;
        for (auto &[c, deg] : indegree) {
            if (deg == 0) {
                q.push(c);
            }
        }
        
        string res;
        while (!q.empty()) {
            char ch = q.front();
            q.pop();
            res += ch;
            for (char neighbor : adj[ch]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return res.size() == indegree.size() ? res : "";
    }
};
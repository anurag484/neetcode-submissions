class Solution {
public:
    string foreignDictionary(vector<string>& words) {
            vector<vector<int>> adj(26);
    vector<int> present(26, 0);  
    vector<int> indeg(26, 0);

    // Mark all present characters
    for (auto &w : words) {
        for (char c : w) {
            present[c - 'a'] = 1;
        }
    }

    // Build graph
    for (int i = 0; i + 1 < words.size(); i++) {
        string &a = words[i], &b = words[i + 1];
        int len = min(a.size(), b.size());
        int j = 0;
        while (j < len && a[j] == b[j]) j++;
        if (j == len) {
            if (a.size() > b.size()) return ""; // invalid prefix
            continue;
        }
        int u = a[j] - 'a', v = b[j] - 'a';
        // Avoid duplicate edges
        bool exists = false;
        for (int nei : adj[u]) if (nei == v) { exists = true; break; }
        if (!exists) {
            adj[u].push_back(v);
            indeg[v]++;
        }
    }

    // Topological sort (Kahn’s algorithm)
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (present[i] && indeg[i] == 0) q.push(i);
    }

    string order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(char('a' + u));
        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    // Check if all present chars included
    int total = 0;
    for (int i = 0; i < 26; i++) if (present[i]) total++;
    if (order.size() != total) return "";

    return order;
    }
};

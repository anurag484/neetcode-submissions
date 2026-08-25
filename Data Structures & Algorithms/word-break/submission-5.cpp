class Solution {
public:
    bool solve(int index, const string &s, unordered_set<string>& st, vector<int>& dp) {
        int n = s.size();
        if (index == n) return true;
        if (dp[index] != -1) return dp[index];

        for (auto &word : st) {
            int len = word.size();
            if (index + len <= n && s.compare(index, len, word) == 0) {
                if (solve(index + len, s, st, dp)) {
                    return dp[index] = true;
                }
            }
        }
        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(0, s, st, dp);
    }
};

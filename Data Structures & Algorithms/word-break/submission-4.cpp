class Solution {
public:
    bool solve(int index, string s, unordered_set<string>& st,vector<int>& dp) {
        int n = s.size();
        if (index == n) {
            return true;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        if(st.find(s)!=st.end()){
            return dp[index]=true;
        }
        for (int i = 1; i <= n; i++) {  // Ensure substring length doesn't exceed bounds
            string temp = s.substr(index, i);
            if (st.find(temp) != st.end() && solve(index + i, s, st,dp)) {
                return dp[index]=true;
            }
        }
        return dp[index]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<int>dp(n+1,-1);
        // for (auto& word : wordDict) {
        //     st.insert(word);
        // }
        return solve(0, s, st,dp);  // Correctly pass the string `s` to `solve`
    }
};

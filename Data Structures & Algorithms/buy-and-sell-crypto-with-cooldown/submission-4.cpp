class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));  
        // +2 size to safely handle i+2 case without extra checks

        for (int i = n-1; i >= 0; --i) {
            // Case 1: Can buy
            dp[i][1] = max(-prices[i] + dp[i+1][0],   // Buy today
                           0 + dp[i+1][1]);          // Skip today

            // Case 2: Can sell
            dp[i][0] = max(prices[i] + dp[i+2][1],   // Sell today, cooldown next day
                           0 + dp[i+1][0]);          // Skip today
        }

        return dp[0][1];  // Start at day 0 with buying option
    }
};

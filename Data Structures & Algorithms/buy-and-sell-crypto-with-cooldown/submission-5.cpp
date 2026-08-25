class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        
        // Base case: no days left
        if (i >= n) return 0;

        // Already computed
        if (dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if (buy) {
            // Two choices: buy today OR skip
            profit = max(-prices[i] + solve(i+1, 0, prices, dp),  // Buy
                         0 + solve(i+1, 1, prices, dp));         // Skip
        } else {
            // Two choices: sell today (with cooldown) OR skip
            profit = max(prices[i] + solve(i+2, 1, prices, dp),  // Sell + cooldown
                         0 + solve(i+1, 0, prices, dp));        // Skip
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);  // Start at day 0 with buying option
    }
};

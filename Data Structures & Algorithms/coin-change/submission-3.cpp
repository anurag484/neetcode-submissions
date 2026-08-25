class Solution {
public:
    int solve(int index, int n, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        // Base case
        if (index == n - 1) {
            if (amount % coins[index] == 0) {
                return amount / coins[index];
            } else {
                return 1e9;  // invalid case
            }
        }

        // Check memoization
        if (dp[index][amount] != -1) return dp[index][amount];

        // Choice 1: not take current coin
        int notTake = solve(index + 1, n, coins, amount, dp);

        // Choice 2: take current coin (if possible)
        int take = INT_MAX;
        if (coins[index] <= amount) {
            take = 1 + solve(index, n, coins, amount - coins[index], dp);
        }

        // Store and return result
        return dp[index][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(0, n, coins, amount, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};

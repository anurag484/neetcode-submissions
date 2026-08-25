class Solution {
public:
    int solve(int index, int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (index == n-1) {
            return (amount % coins[index] == 0);
        }
        if (dp[index][amount] != -1) {
            return dp[index][amount];
        }

        int nottake = solve(index+1, n, amount, coins, dp);
        int take = 0;
        if (coins[index] <= amount) {
            take = solve(index, n, amount - coins[index], coins, dp); // ✅ no +1
        }

        return dp[index][amount] = take + nottake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(0, n, amount, coins, dp);
    }
};

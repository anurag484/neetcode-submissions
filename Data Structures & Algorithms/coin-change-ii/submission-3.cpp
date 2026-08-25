class Solution {
public:
    int solve(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        int n = coins.size();

        // Base case: if we are at the last coin
        if (index == n-1) {
            return (amount % coins[index] == 0); 
        }

        if (dp[index][amount] != -1) return dp[index][amount];

        // Choice 1: not take current coin
        int notTake = solve(index+1, amount, coins, dp);

        // Choice 2: take current coin (stay at same index because we can reuse)
        int take = 0;
        if (coins[index] <= amount) {
            take = solve(index, amount - coins[index], coins, dp);
        }

        return dp[index][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(0, amount, coins, dp);  // start from index 0
    }
};

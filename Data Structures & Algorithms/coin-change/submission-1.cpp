class Solution {
public:
    int solve(int index, int amount, vector<int>& coins, int n) {
        if (index == n - 1) { // last coin
            if (amount % coins[index] == 0) {
                return amount / coins[index];
            } else {
                return 1e9; // not possible
            }
        }

        int notTake = solve(index + 1, amount, coins, n); // skip this coin
        int take = INT_MAX;
        if (coins[index] <= amount) {
            take = 1 + solve(index, amount - coins[index], coins, n); // take same coin again
        }

        return min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = solve(0, amount, coins, n);
        return (ans >= 1e9) ? -1 : ans;
    }
};

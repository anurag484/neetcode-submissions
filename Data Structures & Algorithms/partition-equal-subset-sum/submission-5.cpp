class Solution {
public:
    // Memoized recursive function
    bool solve(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;           // ✅ Found a subset with sum = target
        if (index == nums.size()) return false; // ❌ No elements left to pick

        if (dp[index][target] != -1) return dp[index][target];

        // Option 1: Skip current element
        bool notTake = solve(index + 1, target, nums, dp);

        // Option 2: Take current element if it doesn't exceed target
        bool take = false;
        if (nums[index] <= target) {
            take = solve(index + 1, target - nums[index], nums, dp);
        }

        return dp[index][target] = take || notTake; // Store result
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) sum += num;

        if (sum % 2 != 0) return false;   // ❌ If sum is odd, can't split equally

        int targetSum = sum / 2;
        vector<vector<int>> dp(n, vector<int>(targetSum + 1, -1)); // ✅ Memoization table

        return solve(0, targetSum, nums, dp);
    }
};

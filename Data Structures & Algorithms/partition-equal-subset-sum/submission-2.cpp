class Solution {
public:
    bool solve(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;   // ✅ Found a subset with sum = target
        if (index == nums.size() || target < 0) return false;  // ❌ No more elements to pick

        if (dp[index][target] != -1) return dp[index][target];  // ✅ Use stored result

        // Try including or excluding nums[index]
        bool notTake = solve(index + 1, target, nums, dp);
        bool take = (nums[index] <= target) ? solve(index + 1, target - nums[index], nums, dp) : false;

        return dp[index][target] = take || notTake;  // ✅ Store result
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) sum += num;

        if (sum % 2 != 0) return false;  // ❌ If sum is odd, can't split equally

        int targetSum = sum / 2;
        vector<vector<int>> dp(n, vector<int>(targetSum + 1, -1));  // ✅ Use 2D DP

        return solve(0, targetSum, nums, dp);
    }
};
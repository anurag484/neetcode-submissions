class Solution {
public:
    int solve(int index, int curr_sum, vector<int>& nums, int target, vector<vector<int>>& dp, int offset) {
        // Base case
        if (index == nums.size()) {
            return curr_sum == target;
        }

        // Shifted index for dp
        int shifted = curr_sum + offset;

        // Already computed?
        if (dp[index][shifted] != INT_MIN) {
            return dp[index][shifted];
        }

        // Two choices: +nums[index] or -nums[index]
        int addWay = solve(index + 1, curr_sum + nums[index], nums, target, dp, offset);
        int subWay = solve(index + 1, curr_sum - nums[index], nums, target, dp, offset);

        // Save result
        return dp[index][shifted] = addWay + subWay;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        // If target is not achievable
        if (abs(target) > totalSum) return 0;

        int n = nums.size();

        // dp[n][2*totalSum+1], initialized to INT_MIN (meaning not calculated)
        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, INT_MIN));

        return solve(0, 0, nums, target, dp, totalSum);
    }
};

class Solution {
public:
    int solve(int index, const vector<int>& nums, vector<int>& dp) {
        if (index >= nums.size()) return 0;   // base case
        if (dp[index] != -1) return dp[index];

        // Two choices: rob this house or skip it
        int take = nums[index] + solve(index + 2, nums, dp);
        int notTake = solve(index + 1, nums, dp);

        return dp[index] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // Case 1: exclude last
        vector<int> case1(nums.begin(), nums.end() - 1);
        vector<int> dp1(case1.size(), -1);
        int ans1 = solve(0, case1, dp1);

        // Case 2: exclude first
        vector<int> case2(nums.begin() + 1, nums.end());
        vector<int> dp2(case2.size(), -1);
        int ans2 = solve(0, case2, dp2);

        return max(ans1, ans2);
    }
};

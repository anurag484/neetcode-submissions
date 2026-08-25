class Solution {
public:
    int solve(const vector<int>& nums, int index, vector<int>& dp){
        if (index >= (int)nums.size()) return 0;
        if (dp[index] != -1) return dp[index];
        int take = nums[index] + solve(nums, index + 2, dp);
        int nottake = solve(nums, index + 1, dp);
        return dp[index] = max(take, nottake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];                 // ✅ important edge case
        if (n == 2) return max(nums[0], nums[1]);   // (optional) clearer

        vector<int> case1(nums.begin(), nums.end() - 1); // exclude last
        vector<int> case2(nums.begin() + 1, nums.end()); // exclude first

        vector<int> dp1(case1.size(), -1), dp2(case2.size(), -1);
        int ans1 = solve(case1, 0, dp1);
        int ans2 = solve(case2, 0, dp2);
        return max(ans1, ans2);
    }
};

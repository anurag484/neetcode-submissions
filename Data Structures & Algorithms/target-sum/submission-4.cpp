class Solution {
public:
    int solve(int index, int curr_sum, vector<int>& nums, int target,
              map<pair<int,int>, int>& dp) {
        // Base case
        if (index == nums.size()) {
            return curr_sum == target;
        }

        // Check memo
        if (dp.count({index, curr_sum})) {
            return dp[{index, curr_sum}];
        }

        // Two choices: +nums[index] or -nums[index]
        int addWay = solve(index + 1, curr_sum + nums[index], nums, target, dp);
        int subWay = solve(index + 1, curr_sum - nums[index], nums, target, dp);

        // Store result in dp and return
        return dp[{index, curr_sum}] = addWay + subWay;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>, int> dp;  // memo table
        return solve(0, 0, nums, target, dp);
    }
};

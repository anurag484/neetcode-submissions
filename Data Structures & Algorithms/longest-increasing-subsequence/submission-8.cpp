class Solution {
public:
    int solve(int index, int prevIndex, vector<int>& nums,vector<vector<int>>& dp) {
        if (index == nums.size()) return 0;

        if(dp[index][prevIndex+1]!=-1){
            return dp[index][prevIndex+1];
        }


        // Option 1: Skip current element
        int notTake = solve(index + 1, prevIndex, nums,dp);

        // Option 2: Take current element if valid
        int take = 0;
        if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
            take = 1 + solve(index + 1, index, nums,dp);
        }

        return dp[index][prevIndex+1]=max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0, -1, nums,dp);
    }
};

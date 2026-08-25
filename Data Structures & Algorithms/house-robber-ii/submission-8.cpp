class Solution {
public:
    int solve(const vector<int>& nums){
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        vector<int>dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];                 // ✅ important edge case
        if (n == 2) return max(nums[0], nums[1]);   // (optional) clearer

        vector<int> case1(nums.begin(), nums.end() - 1); // exclude last
        vector<int> case2(nums.begin() + 1, nums.end()); // exclude first

        // vector<int> dp1(case1.size(), -1), dp2(case2.size(), -1);
        int ans1 = solve(case1);
        int ans2 = solve(case2);
        return max(ans1, ans2);
    }
};

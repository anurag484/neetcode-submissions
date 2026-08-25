class Solution {
public:
    int solve(int index,vector<int>& nums,vector<int>& dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int pick=nums[index]+solve(index+2,nums,dp);
        int notpick=0+solve(index+1,nums,dp);
        return dp[index]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
    }
};

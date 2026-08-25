class Solution {
public:
    int solve(vector<int>& nums,int index,vector<int>& dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int pick=nums[index]+solve(nums,index+2,dp);
        int notpick=0+solve(nums,index+1,dp);
        return dp[index]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};

class Solution {
public:
    int solve(int index,int prev_idx,vector<int>& nums,vector<vector<int>>& dp){
        if(index==nums.size()){
            return 0;
        }
        if(dp[index][prev_idx+1]!=-1){
            return dp[index][prev_idx+1];
        }
        int len=0+solve(index+1,prev_idx,nums,dp);
        if(prev_idx==-1 || nums[prev_idx]<nums[index]){
            len=max(len,1+solve(index+1,index,nums,dp));
        }
        return dp[index][prev_idx+1]=len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};

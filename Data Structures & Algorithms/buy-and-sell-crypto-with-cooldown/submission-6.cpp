class Solution {
public:
    int solve(int index,int buy,vector<vector<int>>& dp,vector<int>& prices){
        int n=prices.size();
        if(index>=n){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }

        int profit=0;
        if(buy){
            profit=max(-prices[index]+solve(index+1,0,dp,prices),0+solve(index+1,1,dp,prices));
        }else{
            profit=max(prices[index]+solve(index+2,1,dp,prices),0+solve(index+1,0,dp,prices));
        }

        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,dp,prices);
    }
};

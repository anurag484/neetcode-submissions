class Solution {
public:
    int solve(int index,int n,vector<int>& coins,int amount){
        if(index==n-1){
            if(amount%coins[index]==0){
                return amount/coins[index];
            }else{
                return 1e9;
            }
        }

        int notTake=solve(index+1,n,coins,amount);
        int take=INT_MAX;
        if(coins[index]<=amount){
            take=1+solve(index,n,coins,amount-coins[index]);
        }
        return min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans=solve(0,n,coins,amount);
        return (ans>=1e9)?-1:ans;
    }
};

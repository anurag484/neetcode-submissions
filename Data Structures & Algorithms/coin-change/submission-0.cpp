class Solution {
public:
int solve(int index,int amount,vector<int>& coins){
    if(index==0){
        if(amount%coins[0]==0){
            return amount/coins[0];
        }else{
            return 1e9;
        }
    }
    int notTake=0+solve(index-1,amount,coins);
    int take=INT_MAX;
    if(coins[index]<=amount){
        take=1+solve(index,amount-coins[index],coins);
    }
    return min(take,notTake);

}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
       int ans=solve(n-1,amount,coins); 
       if(ans>=1e9){
        return -1;
       }else{
        return ans;
       }
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int profit=prices[j]-prices[i];
                if(profit>maxprofit){
                    maxprofit=profit;
                }
            }
        }
        return maxprofit;
    }
};

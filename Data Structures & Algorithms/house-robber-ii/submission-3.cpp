class Solution {
public:
int solve(vector<int>& nums){
    int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1){
                take+=dp[i-2];
            }
            int nottake=0+dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[n-1];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>temp1;
        vector<int>temp2;
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        return max(solve(temp1),solve(temp2));
    }
};

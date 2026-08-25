class Solution {
public:
int solve(vector<int>& nums,int curr,int prev){
    int n=nums.size();
    if(curr==n){
        return 0;
    }
    int take=0;
    if(prev==-1 || nums[curr]>nums[prev]){
        take=1+solve(nums,curr+1,curr);
    }
    int nottake=0+solve(nums,curr+1,prev);
    return max(take,nottake);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,0,-1);
    }
};

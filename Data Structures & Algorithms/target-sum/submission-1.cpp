class Solution {
public:
int solve(int i,int curr_sum,vector<int>& nums,int target){
    if(i==nums.size()){
        return curr_sum==target;
    }
    return solve(i+1,curr_sum+nums[i],nums,target)+solve(i+1,curr_sum-nums[i],nums,target);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,0,nums,target);
    }
};

class Solution {
public:
    int solve(int index,int curr_sum,vector<int>& nums,int target){
        if(index==nums.size()){
            return curr_sum==target;
        }
        return solve(index+1,curr_sum+nums[index],nums,target)
        + solve(index+1,curr_sum-nums[index],nums,target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,0,nums,target);
    }
};

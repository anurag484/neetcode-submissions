class Solution {
public:
    int solve(int index,int prev_index,vector<int>& nums){
        if(index==nums.size()){
            return 0;
        }
        int nottake=0+solve(index+1,prev_index,nums);

        int take=0;
        if(prev_index==-1 || nums[index]>nums[prev_index]){
            take=1+solve(index+1,index,nums);
        }

        return max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(0,-1,nums);
    }
};

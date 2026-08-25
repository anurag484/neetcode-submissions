class Solution {
public:
    bool solve(int index,int target,vector<int>& nums){
        if(target==0){
            return true;
        }
        if(index==nums.size()){
            return nums[index]==target;
        }
        bool nottake=solve(index+1,target,nums);
        bool take=false;
        if(nums[index]<=target){
            take=solve(index+1,target-nums[index],nums);
        }
        return nottake||take;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int targetSum=sum/2;
        if(sum%2!=0){
            return false;
        }else{
            return solve(0,targetSum,nums);
        }
    }
};

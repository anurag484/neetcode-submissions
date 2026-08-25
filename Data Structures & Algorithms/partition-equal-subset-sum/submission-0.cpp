class Solution {
public:
bool solve(int target,vector<int>& nums,int index){
    if(target==0){
        return true;
    }
    if(index==0){
        return nums[0]==target;
    }
    bool notTake=solve(target,nums,index-1);
    bool take=false;
    if(nums[index]<=target){
        take=solve(target-nums[index],nums,index-1);
    }
    return take||notTake;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int target=sum/2;
        if(sum%2!=0){
            return false;
        }
        else{
            return solve(target,nums,n-1);
        }
    }
};

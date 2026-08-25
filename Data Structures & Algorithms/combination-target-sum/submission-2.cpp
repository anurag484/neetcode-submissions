class Solution {
public:
    void solve(vector<int>& nums,int target,vector<int>& ds,vector<vector<int>>& ans,int index){
        if(index==nums.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(nums[index]<=target){
            ds.push_back(nums[index]);
            solve(nums,target-nums[index],ds,ans,index);
            ds.pop_back();
        }
        solve(nums,target,ds,ans,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(nums,target,ds,ans,0);
        return ans;
    }
};

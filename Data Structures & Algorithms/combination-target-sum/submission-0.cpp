class Solution {
public:
    void combination(int index,int target,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans){
        if(index==nums.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(nums[index]<=target){
            ds.push_back(nums[index]);
            combination(index,target-nums[index],nums,ds,ans);
            ds.pop_back();
        }
        combination(index+1,target,nums,ds,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        combination(0,target,nums,ds,ans);
        return ans;
    }
};

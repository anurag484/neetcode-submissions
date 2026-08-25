class Solution {
public:
    void solve(int index,vector<int>& nums,vector<int>& subset,vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        solve(index+1,nums,subset,ans);
        subset.pop_back();

        int ind=index+1;
        while(ind<nums.size() && nums[ind]==nums[index]){
            ind++;
        }
        solve(ind,nums,subset,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        sort(nums.begin(),nums.end());
        solve(0,nums,subset,ans);
        return ans;
    }
};

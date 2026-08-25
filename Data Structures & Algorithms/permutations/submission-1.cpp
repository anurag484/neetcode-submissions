class Solution {
public:
    void permuteHelper(vector<int>& nums, vector<vector<int>>& ans, int index) {
        if (index == nums.size()) {  // Base case: If index reaches end, store permutation
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);   // Swap to create a new permutation
            permuteHelper(nums, ans, index + 1); // Recur for the next index
            swap(nums[i], nums[index]);   // Backtrack (undo swap)
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteHelper(nums, ans, 0);  // Start recursion from index 0
        return ans;
    }
};

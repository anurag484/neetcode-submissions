class Solution {
public:
    void printSubsets(vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans, int index) {
        // Base case: When index reaches the size of nums, push the subset into ans
        if(index == nums.size()){
            ans.push_back(subset);
            return;
        }

        // Include the current element nums[index] in the subset
        subset.push_back(nums[index]);
        printSubsets(nums, subset, ans, index + 1);  // Move to the next index

        // Backtrack: remove the current element from the subset
        subset.pop_back();

        // Exclude the current element nums[index] and move to the next index
        printSubsets(nums, subset, ans, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        printSubsets(nums, subset, ans, 0);  // Start recursion from index 0
        return ans;
    }
};

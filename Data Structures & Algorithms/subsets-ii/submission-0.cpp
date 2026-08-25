class Solution {
public:
    void printSubsets(vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans, int index) {
        if (index == nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        printSubsets(nums, subset, ans, index + 1);

        subset.pop_back();

        // Skip duplicates by checking if current element is the same as the previous one
        int ind = index + 1;
        while (ind < nums.size() && nums[ind] == nums[index]) {
            ind++;
        }

        // Only proceed to the next recursive call if the duplicate element is skipped
        printSubsets(nums, subset, ans, ind);  // Skip all duplicate elements at current index
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());  // Sort the array to group duplicates together
        printSubsets(nums, subset, ans, 0);
        return ans;
    }
};

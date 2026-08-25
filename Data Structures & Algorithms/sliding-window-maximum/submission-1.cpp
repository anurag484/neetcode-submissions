class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans; // To store the maximums
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) { // Iterate for each window start
            int maxi = INT_MIN;

            // Find the maximum in the current window
            for (int j = i; j < i + k; j++) {
                maxi = max(maxi, nums[j]);
            }

            ans.push_back(maxi); // Add the maximum to the result
        }

        return ans;
    }
};

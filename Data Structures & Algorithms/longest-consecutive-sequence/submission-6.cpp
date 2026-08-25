class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longest = 0;
        int count = 0;
        int last_smaller = INT_MIN; // Fixed initialization
        
        for (int i = 0; i < nums.size(); i++) {
            if (last_smaller == nums[i] - 1) {
                count++;
                last_smaller = nums[i];
            } else if (last_smaller != nums[i]) { // Avoid resetting on duplicate elements
                count = 1;
                last_smaller = nums[i];
            }
            longest = max(longest, count);
        }
        return longest;
    }
};

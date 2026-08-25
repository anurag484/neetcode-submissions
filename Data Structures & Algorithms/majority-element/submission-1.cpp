class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int cnt = 1;  // count nums[i] itself
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    cnt++;
                }
            }
            if (cnt > n / 2) {
                return nums[i];
            }
        }
        return -1; // this case won't happen if majority element is guaranteed
    }
};

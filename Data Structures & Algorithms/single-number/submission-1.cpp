class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0; // Use a different variable name
        for (int i = 0; i < nums.size(); i++) {
            xorr = xorr ^ nums[i]; // XOR all numbers
        }
        return xorr;
    }
};

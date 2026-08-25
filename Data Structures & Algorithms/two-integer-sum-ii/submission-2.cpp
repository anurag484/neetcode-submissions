class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            int num = numbers[i];
            int remain = target - num;
            
            if (mp.find(remain) != mp.end()) {
                // Return the smaller index first, followed by the larger one
                return {mp[remain] + 1, i + 1};
            }
            
            // Store the number and its index
            mp[num] = i;
        }
        
        return {}; // No solution found
    }
};

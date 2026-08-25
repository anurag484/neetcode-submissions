class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0); // Initialize result with zeros
        for (int i = 0; i < temperatures.size(); i++) {
            int count = 0; // Count the number of days until a warmer day
            for (int j = i + 1; j < temperatures.size(); j++) {
                count++;
                if (temperatures[j] > temperatures[i]) { // Find the next warmer day
                    result[i] = count;
                    break;
                }
            }
        }
        return result;
    }
};

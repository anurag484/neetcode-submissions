class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);  // Initialize ans with zeros
        stack<pair<int, int>> st;  // Stack to store temperature and its index

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            // Check while the stack is not empty and the current temperature is greater
            // than the temperature at the top of the stack
            while (!st.empty() && t > st.top().first) {
                auto pair = st.top();
                st.pop();
                ans[pair.second] = i - pair.second;  // Calculate the number of days
            }
            // Push the current temperature and its index to the stack
            st.push({t, i});
        }
        return ans;  // Return the final answer
    }
};

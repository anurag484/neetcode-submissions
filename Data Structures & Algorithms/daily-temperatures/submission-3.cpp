class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; --i) {
            // Remove all smaller or equal temperatures
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }

            // If the stack is empty, no warmer days
            if (st.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = st.top() - i;
            }

            st.push(i);  // Push current index
        }

        return ans;
    }
};

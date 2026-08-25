class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) { // Directly iterate over characters
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch); // Push opening brackets onto the stack
            } else {
                if (st.empty()) {
                    return false; // Closing bracket with no matching opening bracket
                }
                // Check for matching pairs
                if ((ch == ')' && st.top() == '(') ||
                    (ch == ']' && st.top() == '[') ||
                    (ch == '}' && st.top() == '{')) {
                    st.pop(); // Valid pair, so pop the opening bracket
                } else {
                    return false; // Mismatch found
                }
            }
        }
        return st.empty(); // If stack is empty, all brackets were matched
    }
};

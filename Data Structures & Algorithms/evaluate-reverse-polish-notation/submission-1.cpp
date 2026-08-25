class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;  // Stack to evaluate expressions
        for (const auto& ch : tokens) {
            if (ch == "+") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b + a);  // Perform addition
            } else if (ch == "-") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b - a);  // Perform subtraction (note the order)
            } else if (ch == "*") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b * a);  // Perform multiplication
            } else if (ch == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b / a);  // Perform division (note the order)
            } else {
                st.push(stoi(ch));  // Convert string to integer and push onto the stack
            }
        }
        return st.top();  // The final result will be at the top of the stack
    }
};

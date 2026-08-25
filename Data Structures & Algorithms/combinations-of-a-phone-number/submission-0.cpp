class Solution {
public:
    void solve(int index, string& digits, string& temp, vector<string>& digitToChar, vector<string>& ans) {
        // Base case: if we've processed all digits, store the combination
        if (index == digits.length()) {
            ans.push_back(temp);
            return;
        }

        // Get the corresponding characters for the current digit
        char ch = digits[index]; 
        string str = digitToChar[ch - '0']; // Convert digit character to integer index

        // Iterate through the mapped characters and recursively solve
        for (int i = 0; i < str.length(); i++) {
            temp.push_back(str[i]);                // Add character to the current combination
            solve(index + 1, digits, temp, digitToChar, ans); // Move to the next digit
            temp.pop_back();                      // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        // Handle empty input case
        if (digits.empty()) {
            return {};
        }

        vector<string> ans;
        string temp = "";
        vector<string> digitToChar = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        }; // Corrected mapping

        solve(0, digits, temp, digitToChar, ans);
        return ans;
    }
};

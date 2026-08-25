class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0;
        
        // Left to right: Checking if ')' is ever more than '('
        for (char c : s) {
            if (c == '(' || c == '*') balance++; 
            else balance--; 
            
            if (balance < 0) return false; // More ')' than '('
        }
        
        balance = 0;
        
        // Right to left: Checking if '(' is ever more than ')'
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') balance++;
            else balance--;
            
            if (balance < 0) return false; // More '(' than ')'
        }
        
        return true;
    }
};

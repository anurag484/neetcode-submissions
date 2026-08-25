class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0;
        
        // Pass 1: left to right
        for (char c : s) {
            if (c == '(' || c == '*') balance++;
            else balance--;   // <-- handle ')'
            
            if (balance < 0) return false; 
        }
        
        balance = 0;
        
        // Pass 2: right to left
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') balance++;
            else balance--;   // <-- handle '('
            
            if (balance < 0) return false;
        }
        
        return true;
    }
};

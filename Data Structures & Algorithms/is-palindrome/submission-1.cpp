class Solution {
public:
    bool isPalindrome(string s) {
        string newstr = "";
        for (char c : s) {
            if (isalnum(c)) {
                newstr += tolower(c); // Add only alphanumeric characters in lowercase
            }
        }

        // Create a reversed version of the cleaned string
        string reversedStr = newstr;
        reverse(reversedStr.begin(), reversedStr.end());

        // Compare the original cleaned string with the reversed version
        return newstr == reversedStr;
    }
};

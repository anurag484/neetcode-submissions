class Solution {
public:
    int start, maxLen, n;
    string s;

    void expand(int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }

    string longestPalindrome(string str) {
        s = str;
        n = s.size();
        if (n == 0) return "";

        start = 0;
        maxLen = 1;

        for (int i = 0; i < n; i++) {
            expand(i, i);     // odd length
            expand(i, i + 1); // even length
        }

        return s.substr(start, maxLen);
    }
};

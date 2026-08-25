class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) {
        return false;
    }
    
    // Sort s1 for later comparison
    sort(s1.begin(), s1.end());
    
    // Traverse s2 with a sliding window
    for (int i = 0; i <= s2.length() - s1.length(); i++) {
        string substring = s2.substr(i, s1.length());
        sort(substring.begin(), substring.end());
        if (s1 == substring) {
            return true;
        }
    }
    
    return false;
}

};

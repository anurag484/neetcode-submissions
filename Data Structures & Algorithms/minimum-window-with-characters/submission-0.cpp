class Solution {
public:
    string minWindow(string s, string t) {
    int i = 0, j = 0, start = 0, mini = INT_MAX;
    unordered_map<char, int> mp;

    // Populate the frequency map for `t`
    for (char c : t) {
        mp[c]++;
    }

    int count = mp.size(); // Distinct characters to match

    // Sliding window
    while (j < s.size()) {
        // Decrease the count for the current character
        if (mp.find(s[j]) != mp.end()) {
            mp[s[j]]--;
            if (mp[s[j]] == 0) {
                count--;
            }
        }

        // Shrink the window if all characters are matched
        while (count == 0) {
            if (j - i + 1 < mini) {
                mini = j - i + 1;
                start = i;
            }
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    count++;
                }
            }
            i++;
        }

        j++;
    }

    // Return the result
    return mini == INT_MAX ? "" : s.substr(start, mini);
}

};

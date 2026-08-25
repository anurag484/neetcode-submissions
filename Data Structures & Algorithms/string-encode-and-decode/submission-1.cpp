class Solution {
public:
    string encode(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        vector<int> sizes;
        string res = "";
        for (auto s : strs) {
            sizes.push_back(s.size());
        }
        for (auto sz : sizes) {
            res += to_string(sz) + ',';
        }
        res += '#';
        for (auto s : strs) {
            res += s;
        }
        return res; // Correctly return `res`
    }

    vector<string> decode(string s) {
        if (s.empty()) {
            return {};
        }
        vector<int> sizes;
        vector<string> res;
        int i = 0;

        // Extract sizes from the string until the delimiter '#'
        while (s[i] != '#') {
            string curr = "";
            while (s[i] != ',') {
                curr += s[i];
                i++;
            }
            sizes.push_back(stoi(curr));
            i++;
        }
        i++; // Move past the '#' delimiter

        // Extract strings based on the sizes
        for (auto sz : sizes) {
            res.push_back(s.substr(i, sz)); // Use `s.substr()` correctly
            i += sz;
        }
        return res;
    }
};

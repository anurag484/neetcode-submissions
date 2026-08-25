class Solution {
public:
    string encode(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }

        vector<int> sizes;
        string res = "";

        // Step 1: Record sizes of each string
        for(auto &it : strs) {
            sizes.push_back(it.size());
        }

        // Step 2: Append sizes with ',' separator
        for(auto &it : sizes) {
            res += to_string(it) + ',';
        }

        // Step 3: Add '#' as delimiter between sizes and actual strings
        res += '#';

        // Step 4: Append all strings one after another
        for(auto &it : strs) {
            res += it;
        }

        return res;
    }

    vector<string> decode(string s) {
        if(s.empty()) {
            return {};
        }

        vector<int> sizes; // ✅ FIXED: Correct type
        vector<string> res;
        int i = 0;

        // Step 1: Parse sizes until '#'
        while(s[i] != '#') {
            string curr = "";
            while(s[i] != ',') {
                curr += s[i];
                i++;
            }
            sizes.push_back(stoi(curr));
            i++; // skip comma
        }

        i++; // skip '#'

        // Step 2: Extract strings using parsed sizes
        for(auto &size : sizes) {
            string part = s.substr(i, size);
            res.push_back(part);
            i += size;
        }

        return res;
    }
};


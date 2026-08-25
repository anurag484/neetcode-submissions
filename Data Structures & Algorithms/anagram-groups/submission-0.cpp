class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto it:strs){
            string sorted=it;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(it);
        }
        vector<vector<string>>result;
        for(auto it:mp){
            result.push_back(it.second);
        }
        return result;
    }
};

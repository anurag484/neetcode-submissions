class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto it:strs){
            vector<int>count(26,0);
            for(char c:it){
                count[c-'a']++;
            }
            string key=to_string(count[0]);
            for(int i=1;i<26;i++){
                key+=','+to_string(count[i]);
            }
            mp[key].push_back(it);
        }
        vector<vector<string>>result;
        for(auto it:mp){
            result.push_back(it.second);
        }
        return result;
    }
};

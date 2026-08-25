class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        vector<int>charCount(26,0);
        for(char ch:s){
            charCount[ch-'a']++;
        }
        for(char ch:t){
            charCount[ch-'a']--;
            if(charCount[ch-'a']<0){
                return false;
            }
        }
        return true;
    }
};

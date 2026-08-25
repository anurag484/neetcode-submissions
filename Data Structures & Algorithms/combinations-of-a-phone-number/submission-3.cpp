class Solution {
public:
    void solve(int index,string digits,unordered_map<char,string>& digitToChar,string& temp,vector<string>& ans){
        if(index==digits.length()){
            ans.push_back(temp);
            return;
        }
        char ch=digits[index];
        string str=digitToChar[ch];
        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            solve(index+1,digits,digitToChar,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
           unordered_map<char, string> digitToChar = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string>ans;
        string temp;
        solve(0,digits,digitToChar,temp,ans);
        return ans;
    }
};

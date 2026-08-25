class Solution {
public:
    bool isPalindrome(string s) {
        string newstr="";
        for(char c:s){
            if(isalnum(c)){
                newstr+=tolower(c);
            }
        }
        string revstr=newstr;
        reverse(revstr.begin(),revstr.end());
        return newstr==revstr;
    }
};

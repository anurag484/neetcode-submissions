class Solution {
public:
    bool isPalindrome(string& s,int left,int right){
        if(left>=right){
            return true;
        }
        if(s[left]==s[right]){
            return isPalindrome(s,left+1,right-1);
        }
        return false;
    }
    int countSubstrings(string s) {
        int count=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};

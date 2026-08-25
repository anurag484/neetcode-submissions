class Solution {
public:  
    void expand(string& s,int l,int r,int& count){
        int n=s.size();
        while(l>=0 && r<n && s[l]==s[r]){
            count++;
            l--;
            r++;
        }
    }
    int countSubstrings(string s) {
        int n=s.size();
        if(n==1){
            return 1;
        }
        int count=0;
        for(int i=0;i<n;i++){
            expand(s,i,i,count);
            expand(s,i,i+1,count);
        }
        return count;
    }
};

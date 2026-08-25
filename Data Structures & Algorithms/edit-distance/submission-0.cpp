class Solution {
public:
int solve(int i,int j,string s1,string s2){
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(s1[i]==s2[j]){
        return solve(i-1,j-1,s1,s2);
    }
    return 1+min(solve(i-1,j,s1,s2),min(solve(i,j-1,s1,s2),solve(i-1,j-1,s1,s2)));
}
    int minDistance(string word1, string word2) {
       int n=word1.size();
       int m=word2.size();
       return solve(n-1,m-1,word1,word2); 
    }
};

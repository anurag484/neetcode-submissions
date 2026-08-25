class Solution {
public:
bool solve(string s,int i,int j,vector<vector<int>>& dp){
    if(i>=j){
        return true;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==s[j]){
        return dp[i][j]=solve(s,i+1,j-1,dp);
    }else{
        return dp[i][j]=false;
    }
}
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=0;
        int start=0;
        int end=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)){
                    if(j-i+1>maxi){
                        maxi=j-i+1;
                        start=i;
                        end=j;
                    }
                }
            }
        }
        string str="";
        for(int i=start;i<=end;i++){
            str+=s[i];
        }
        return str;
    }
};

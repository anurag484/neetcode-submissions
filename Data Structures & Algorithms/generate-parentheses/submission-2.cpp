class Solution {
public:
    void solve(int open,int closed,int n,vector<string>& ans,string& curr){
        if(open==closed && open==n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            curr+='(';
            solve(open+1,closed,n,ans,curr);
            curr.pop_back();
        }
        if(closed<open){
            curr+=')';
            solve(open,closed+1,n,ans,curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr;
        solve(0,0,n,ans,curr);
        return ans;
    }
};

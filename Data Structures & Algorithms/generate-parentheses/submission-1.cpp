class Solution {
public:
vector<string>result;
bool isvalid(string& str){
    int count=0;
    for(char ch:str){
        if(ch=='('){
            count++;
        }else{
            count--;
        }
        if(count<0){
            return false;
        }
    }
    return count==0;
}
void solve(string& curr,int n){
    if(curr.length()==2*n){
        if(isvalid(curr)){
            result.push_back(curr);
        }
        return;
    }
    curr.push_back('(');
    solve(curr,n);
    curr.pop_back();

    curr.push_back(')');
    solve(curr,n);
    curr.pop_back();
}
    // void solve(int open,int closed,int n,vector<string>& ans,string& curr){
    //     if(open==closed && open==n){
    //         ans.push_back(curr);
    //         return;
    //     }
    //     if(open<n){
    //         curr+='(';
    //         solve(open+1,closed,n,ans,curr);
    //         curr.pop_back();
    //     }
    //     if(closed<open){
    //         curr+=')';
    //         solve(open,closed+1,n,ans,curr);
    //         curr.pop_back();
    //     }
    // }
    vector<string> generateParenthesis(int n) {
        // vector<string>ans;
        // string curr;
        // solve(0,0,n,ans,curr);
        // return ans;
        string curr="";
        solve(curr,n);
        return result;
    }
};

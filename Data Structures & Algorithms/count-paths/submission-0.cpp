class Solution {
public:
int solve(int rows,int cols){
    if(rows==0 && cols==0){
        return 1;
    }
    if(rows<0 || cols<0){
        return 0;
    }
    int up=solve(rows-1,cols);
    int left=solve(rows,cols-1);
    return up+left;
}
    int uniquePaths(int m, int n) {
        return solve(m-1,n-1);
    }
};

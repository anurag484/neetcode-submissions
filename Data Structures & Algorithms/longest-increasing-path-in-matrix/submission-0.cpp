class Solution {
public:
int dfs(int i,int j,vector<vector<int>>& matrix){
    int n=matrix.size();
    int m=matrix[0].size();

    int ans=1;
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};

    for(int ind=0;ind<4;ind++){
        int new_i=i+dx[ind];
        int new_j=j+dy[ind];

        if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && matrix[i][j]<matrix[new_i][new_j]){
            ans=max(ans,1+dfs(new_i,new_j,matrix));
        }
    }
    return ans;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int longest=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                longest=max(longest,dfs(i,j,matrix));
            }
        }
        return longest;
    }
};

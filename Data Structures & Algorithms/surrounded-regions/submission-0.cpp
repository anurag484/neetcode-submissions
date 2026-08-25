class Solution {
public:
void dfs(int row,int col,vector<vector<int>>& visited,vector<vector<char>>& board){
    visited[row][col]=1;
    int n=board.size();
    int m=board[0].size();
    
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};

    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && !visited[nrow][ncol] && board[nrow][ncol]=='O'){
            dfs(nrow,ncol,visited,board);
        }
    }

}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int j=0;j<m;j++){

            // first row
            if(!visited[0][j] && board[0][j]=='O'){
                dfs(0,j,visited,board);
            }

            // last row
            if(!visited[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,visited,board);
            }
        }

        for(int i=0;i<n;i++){

            // first col
            if(!visited[i][0] && board[i][0]=='O'){
                dfs(i,0,visited,board);
            }

            // last col
            if(!visited[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,visited,board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};

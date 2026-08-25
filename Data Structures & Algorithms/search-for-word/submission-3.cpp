class Solution {
public:
    bool solve(int row,int col,string& word,vector<vector<char>>& board,int index){
        if(index==word.size()){
            return true;
        }
        int n=board.size();
        int m=board[0].size();
        
        if(row<0 || row>=n || col<0 || col>=m || board[row][col]!=word[index]){
            return false;
        }

        char temp=board[row][col];
        board[row][col]='.';  // mark visited

        int row_dir[4]={1,-1,0,0};
        int col_dir[4]={0,0,-1,1};

        for(int dir=0;dir<4;dir++){
            int newr = row + row_dir[dir];
            int newc = col + col_dir[dir];

            if(solve(newr,newc,word,board,index+1)){
                return true;
            }
        }

        board[row][col]=temp; // restore
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        if(word.size()>n*m){
            return false;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && solve(i,j,word,board,0)){
                    return true;
                }
            }
        }
        return false;
    }
};

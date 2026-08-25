class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& visited,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]=='0' || visited[row][col]){
            return;
        }
        visited[row][col]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int newr=row+drow[k];
            int newc=col+dcol[k];
            dfs(newr,newc,visited,grid);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    dfs(i,j,visited,grid);
                }
            }
        }
        return count;
    }
};

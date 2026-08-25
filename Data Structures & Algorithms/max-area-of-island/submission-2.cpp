class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>& visited,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]==0 || visited[row][col]){
            return 0;
        }
        visited[row][col]=1;
        int area=1;

        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            area+=dfs(nrow,ncol,visited,grid);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int max_area=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int area=dfs(i,j,visited,grid);
                    max_area=max(max_area,area);
                }
            }
        }
        return max_area;
    }
};

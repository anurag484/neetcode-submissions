class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
        /*
        int rows=matrix.size();
        int columns=matrix[0].size();
        int low=0;
        int high=rows*columns-1;
        while(low<=high){
            int mid=low+((high-low)/2);
            int row_index=mid/columns;
            int col_index=mid%columns;
            if(matrix[row_index][col_index]==target){
                return true;
            }
            else if(matrix[row_index][col_index]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
        */
    }
};

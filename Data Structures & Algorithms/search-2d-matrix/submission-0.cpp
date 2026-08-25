class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
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
    }
};

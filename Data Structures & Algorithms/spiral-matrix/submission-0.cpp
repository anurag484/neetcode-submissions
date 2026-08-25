class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while(top <= bottom && left <= right) {
            // Traverse top row from left to right
            for(int j = left; j <= right; j++)
                result.push_back(matrix[top][j]);
            top++; // move top boundary down

            // Traverse right column from top to bottom
            for(int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--; // move right boundary left

            // Traverse bottom row from right to left (check if still valid)
            if(top <= bottom) {
                for(int j = right; j >= left; j--)
                    result.push_back(matrix[bottom][j]);
                bottom--; // move bottom boundary up
            }

            // Traverse left column from bottom to top (check if still valid)
            if(left <= right) {
                for(int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++; // move left boundary right
            }
        }

        return result;
    }
};

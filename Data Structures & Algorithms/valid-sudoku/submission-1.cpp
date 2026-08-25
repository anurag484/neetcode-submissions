class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char current = board[i][j];
                if (current == '.') continue;

                // Calculate box index
                int boxIndex = (i / 3) * 3 + (j / 3);

                // Check if current number is already in the row, column, or box
                if (rows[i].count(current) || cols[j].count(current) || boxes[boxIndex].count(current)) {
                    return false;
                }

                // Add current number to the respective sets
                rows[i].insert(current);
                cols[j].insert(current);
                boxes[boxIndex].insert(current);
            }
        }

        return true; // Board is valid
    }
};

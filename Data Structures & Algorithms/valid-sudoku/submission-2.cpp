class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Create 9 sets for rows, 9 for cols, 9 for boxes
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                
                if (val == '.') continue; // Skip blanks

                // Calculate which of the 9 boxes we are in
                int boxIndex = (r / 3) * 3 + (c / 3);

                // If the value is ALREADY in the row, col, or box set, it's invalid!
                if (rows[r].count(val) || cols[c].count(val) || boxes[boxIndex].count(val)) {
                    return false;
                }

                // Otherwise, add it to our tracking sets
                rows[r].insert(val);
                cols[c].insert(val);
                boxes[boxIndex].insert(val);
            }
        }
        return true;
    }
};
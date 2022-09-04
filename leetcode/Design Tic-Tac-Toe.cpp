// space complexity: O(4n) ~= O(n)
// time complexity: O(1)

class TicTacToe {
public:
    int diag, diagRev, size;
    vector<int> rows, cols;
    
    TicTacToe(int n) {
        rows.assign(n, 0);
        cols.assign(n, 0);
        diag = 0, diagRev = 0;
        size = n;
    }
    
    int move(int row, int col, int player) {
        if (player == 1) {
            rows[row]--;
            cols[col]--;
        }
        else if (player == 2) {
            rows[row]++;
            cols[col]++;
        }
        
        if (row == col) {
            if (player == 1)
                diag--;
            else
                diag++;
        }
        
        if (col == (size - row - 1)) {
            if (player == 1)
                diagRev--;
            else
                diagRev++;
        }
        
        if (abs(diag) == size || abs(diagRev) == size || abs(rows[row]) == size || abs(cols[col]) == size)
            return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

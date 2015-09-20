class Solution {
public:
    
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        rows = board.size();
        cols =board[0].size();
        if (rows < 3 || cols < 3)
            return;
        for (int col = 0; col < cols; ++col) {
            if (board[0][col] == 'O')
                dfs(board, 0, col);
            if (board[rows - 1][col] == 'O')
                dfs(board, rows - 1, col);
        }
        for (int row = 1; row < rows - 1; ++row) {
            if (board[row][0] == 'O')
                dfs(board, row, 0);
            if (board[row][cols - 1] == 'O')
                dfs(board, row, cols - 1);
        }
        for (int row = 0; row < rows; ++row)
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == 'O')
                    board[row][col] = 'X';
                else if (board[row][col] == 'N')
                    board[row][col] = 'O';
            }
    }
    private:
    int rows;
    int cols;
    void dfs(vector<vector<char> > &board, int i, int j) {
        board[i][j] = 'N';
        // no need to consider the peripheral border, so the condition
        // is i > 1, i < rows - 2, not i > 0, i < rows - 1.
        //
        // if use i > 0, i < rows - 1, DFS solution will get a Runtime Error, confusing!
        if (i > 1 && board[i - 1][j] == 'O')
            dfs(board, i - 1, j);
        if (i < rows - 2 && board[i + 1][j] == 'O')
            dfs(board, i + 1, j);
        if (j > 1 && board[i][j - 1] == 'O')
            dfs(board, i, j - 1);
        if (j < cols - 2 && board[i][j + 1] == 'O')
            dfs(board, i, j + 1);
    }
    
};
class Solution {
public:
    void dfs(int row, int col, int m, int n, vector<vector<char>>& board, vector<vector<int>>& vis)
    {
        vis[row][col] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int x = 0; x < 4; x++)
        {
            int nrow = row + drow[x];
            int ncol = col + dcol[x];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0)
            {
                dfs(nrow, ncol, m, n, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0)); // ✅ fixed dimensions

        // First row & last row
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(0, j, m, n, board, vis);
            if (board[m-1][j] == 'O') dfs(m-1, j, m, n, board, vis);
        }

        // First column & last column
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(i, 0, m, n, board, vis);
            if (board[i][n-1] == 'O') dfs(i, n-1, m, n, board, vis);
        }

        // Flip unvisited 'O's to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

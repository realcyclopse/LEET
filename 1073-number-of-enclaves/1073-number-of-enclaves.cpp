class Solution {
public:
    void dfs(int row, int col, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& vis)
    {
        vis[row][col]= 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int x = 0; x < 4; x++)
        {
            int nrow = row + drow[x];
            int ncol = col + dcol[x];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
            {
                dfs(nrow, ncol, m, n, grid, vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0;i<n;i++)
        {
            if(grid[0][i]==1) dfs(0,i,m,n,grid,vis);
            if(grid[m-1][i]==1) dfs(m-1,i,m,n,grid,vis);
        }
        for(int j = 0;j<m;j++)
        {
            if(grid[j][0]==1) dfs(j,0,m,n,grid,vis);
            if(grid[j][n-1]==1) dfs(j,n-1,m,n,grid,vis);
        }
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
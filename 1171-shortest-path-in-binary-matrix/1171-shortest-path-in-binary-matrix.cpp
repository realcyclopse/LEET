class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;
        q.push({{0,0}, 1});

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            if (row == n-1 && col == n-1) return dis; // reached target

            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int nrow = row + dr;
                    int ncol = col + dc;

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n) {
                        if (grid[nrow][ncol] == 0 && dist[nrow][ncol] > dis + 1) {
                            dist[nrow][ncol] = dis + 1;
                            q.push({{nrow, ncol}, dis + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>> 
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto [dis, pos] = pq.top();
            pq.pop();
            int row = pos.first, col = pos.second;

            if (row == n-1 && col == m-1) return dis;

            for (auto &d : dirs) {
                int nrow = row + d[0];
                int ncol = col + d[1];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newEffort = max(dis, abs(heights[nrow][ncol] - heights[row][col]));
                    if (newEffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};

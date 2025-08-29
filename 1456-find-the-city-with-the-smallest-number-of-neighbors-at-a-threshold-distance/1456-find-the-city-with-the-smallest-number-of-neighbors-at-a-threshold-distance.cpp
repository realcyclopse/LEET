class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;  // large enough to avoid overflow
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        // distance to itself = 0
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        
        // fill edges (undirected, and keep minimum weight if multiple edges)
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = min(dist[v][u], w);
        }
        
        // Floyd–Warshall: all-pairs shortest path
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // count reachable neighbors within distanceThreshold
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    cnt[i]++;
                }
            }
        }
        
        // find the city with smallest count (break ties by larger index)
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (cnt[i] <= cnt[ans]) ans = i;
        }
        
        return ans;
    }
};

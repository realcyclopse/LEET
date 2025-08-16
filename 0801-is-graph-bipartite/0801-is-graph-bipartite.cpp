class Solution {
public:
    bool dfs(int node, int col, int n, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = col;

        // loop through all neighbors of node
        for (int j = 0; j < graph[node].size(); j++) {
            int neigh = graph[node][j];

            if (color[neigh] == -1) {
                if (!dfs(neigh, 1 - col, n, graph, color))
                    return false;
            }
            else if (color[neigh] == col) {
                return false; // conflict
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, n, graph, color))
                    return false;
            }
        }
        return true;
    }
};
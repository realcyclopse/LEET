class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> out(n, 0);               // outdegree
        vector<vector<int>> rev(n);          // reverse graph
        queue<int> q;
        vector<int> ans;

        // Build outdegree + reverse edges
        for (int u = 0; u < n; u++) {
            out[u] = graph[u].size();
            for (int j = 0; j < graph[u].size(); j++) {
                int v = graph[u][j];
                rev[v].push_back(u); // reverse edge v -> u
            }
            if (out[u] == 0) {
                q.push(u);
            }
        }

        // Kahn's algorithm on reverse graph
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int i = 0; i < rev[node].size(); i++) {
                int neigh = rev[node][i];
                out[neigh]--;
                if (out[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

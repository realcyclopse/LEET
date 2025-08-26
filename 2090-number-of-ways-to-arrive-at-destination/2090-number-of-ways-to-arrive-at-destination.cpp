class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int s = roads[i][0];
            int d = roads[i][1];
            int t = roads[i][2];
            adj[s].push_back({d, t});
            adj[d].push_back({s, t});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<int> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        pq.push({0,0});
        ways[0] = 1;
        dist[0] = 0;
        const int MOD = 1e9+7;
        while(!pq.empty())
        {
            int node = pq.top().second;
            long long d = pq.top().first;
            pq.pop();
            if (d > dist[node]) continue;
            for(int i = 0;i<adj[node].size();i++)
            {
                int next = adj[node][i].first;
                long long nd = adj[node][i].second + d;
                if(nd==dist[next])
                {
                    ways[next] = (ways[next] + ways[node])%MOD;
                    // optional: no need to push again since dist[next] unchanged
                }
                else if(nd<dist[next])
                {
                    dist[next] = nd;
                    ways[next] = ways[node];
                    pq.push({nd,next});
                }

            }
        }
        return ways[n-1];
    }
};

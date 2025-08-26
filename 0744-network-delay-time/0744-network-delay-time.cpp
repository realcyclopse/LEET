class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for (int i = 0; i < times.size(); i++) {
            int s = times[i][0];
            int d = times[i][1];
            int t = times[i][2];
            adj[s].push_back({d, t});
        }

        vector<int> mint(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        mint[k] = 0;
        pq.push({0, k});
        while(!pq.empty())
        {
            int mt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(int i = 0;i<adj[node].size();i++)
            {
                int newt = adj[node][i].second + mt;
                if(newt<mint[adj[node][i].first])
                {
                    mint[adj[node][i].first]= newt;
                    pq.push({newt,adj[node][i].first});
                }
            }
        }
        int ti = 0;
        for(int i = 1;i<=n;i++)
        {
            ti = max(ti,mint[i]);
            if(mint[i] == INT_MAX) return -1;
        }
        return ti;
    }
};

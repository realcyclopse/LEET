class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0;i<flights.size();i++)
        {
            int from = flights[i][0];
            int to = flights[i][1];
            int cost = flights[i][2];
            adj[from].push_back({to,cost});
        }
        vector<int> fincost(n,INT_MAX);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty())
        {
            int stop = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();
            if(stop<=k)
            {
                for(int i = 0;i<adj[node].size();i++)
                {
                    int newPrice = price + adj[node][i].second;
                    if(newPrice < fincost[adj[node][i].first]) {
                    fincost[adj[node][i].first] = newPrice;
                    q.push({stop+1, {adj[node][i].first, newPrice}});
                    }
                }

            }
        }
        if(fincost[dst]==INT_MAX) return -1;
        else return fincost[dst];
    }
};
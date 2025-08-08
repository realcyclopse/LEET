class Solution {
    
public:
    void dfs(int node,vector<vector<int>>& adj, vector<int>& vis)
    {
        for(auto it: adj[node])
        {
            if(vis[it]==0)
            {
                vis[it]= 1;
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<int> vis(n+1,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        
        for(int i =0;i<n;i++)
        {
            if(vis[i]==0)
            {   cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};
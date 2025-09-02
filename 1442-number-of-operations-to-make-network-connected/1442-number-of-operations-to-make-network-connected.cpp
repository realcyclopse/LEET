class DisjointSet {
    vector<int> size, parent;
public:
    DisjointSet(int n)
    {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int findpar(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] = findpar(parent[node]);
    }
    void unionbyrank(int u, int v)
    {
        int ultp_u = findpar(u);
        int ultp_v = findpar(v);
        if(ultp_u == ultp_v) return;
        if(size[ultp_u] < size[ultp_v])
        {
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        }
        else 
        {
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables = connections.size();
        if(cables < n-1) return -1; // not enough edges

        DisjointSet ds(n);

        // union all edges
        for(int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            ds.unionbyrank(u, v);
        }

        // count number of components
        int components = 0;
        for(int i = 0; i < n; i++)
        {
            if(ds.findpar(i) == i) components++;
        }

        return components - 1;
    }
};

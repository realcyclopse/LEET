class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> ind(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
    int u = prerequisites[i][0]; // course
    int v = prerequisites[i][1]; // prerequisite
    adj[v].push_back(u);         // directed edge
    ind[u]++;
}

        for(int i = 0;i<numCourses;i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int i = 0; i<adj[node].size();i++)
            {
                int neigh = adj[node][i];
                ind[neigh]--;
                if(ind[neigh]==0) q.push(neigh);
            }
            ans.push_back(node);
        }
        if (ans.size() != numCourses) return {};
        return ans;
    }
};
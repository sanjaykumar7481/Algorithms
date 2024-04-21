class Solution {
public:
    void dfs(int n,vector<vector<int>>&adj,vector<int>&vis)
    {
        vis[n]=1;
        for(auto i:adj[n])
        {
            if(!vis[i])dfs(i,adj,vis);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(source,adj,vis);
        return vis[destination];
    }
};
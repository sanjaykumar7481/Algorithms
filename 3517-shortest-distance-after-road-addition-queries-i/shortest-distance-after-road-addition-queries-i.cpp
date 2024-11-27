class Solution {
public:
    void dijkstra(vector<int>adj[],vector<int>&dist)
    {
        queue<int>q;
        q.push(0);
        dist[0]=0;
        while(!q.empty())
        {
            auto par=q.front();
            q.pop();
            for(auto i:adj[par])
            {
                if(dist[i]>=1+dist[par])
                {
                    dist[i]=1+dist[par];
                    q.push(i);
                }
            }
        }
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>dist(n,1e5),res;
        vector<int>adj[n];
        for(int i=0;i<n-1;i++)adj[i].push_back(i+1);
        for(auto i:queries)
        {
            adj[i[0]].push_back(i[1]);
            dijkstra(adj,dist);
            res.push_back(dist[n-1]);
        }
        return res;
    }
};
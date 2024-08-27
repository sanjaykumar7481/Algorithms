class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double>dist(n,0.00000);
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        queue<pair<double,int>>q;
        dist[start_node]=1e9;
        q.push({1,start_node});
        while(!q.empty())
        {
            auto a=q.front();
            q.pop();
            for(auto i:adj[a.second])
            {
                if(dist[i.first]<a.first*i.second){
                    dist[i.first]=a.first*i.second;
                    q.push({dist[i.first],i.first});
                }
            }
        }
        return dist[end_node];
    }
};
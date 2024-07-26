class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        int res=0,temp=INT_MAX;
        vector<vector<int>>adj[n];
        for(auto i:edges)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        for(int i=0;i<n;i++)
        {
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            vector<int>dist(n,1e9);
            dist[i]=0;
            pq.push({i,0});
            while(!pq.empty())
            {
                auto a=pq.top();
                pq.pop();
                for(auto j:adj[a.first])
                {
                    if(a.second+j[1]<=k and dist[j[0]]>a.second+j[1])
                    {
                        dist[j[0]]=a.second+j[1];
                        pq.push({j[0],dist[j[0]]});
                    }
                }
            }
            int c=0;
            for(auto p:dist)if(p<=k)c++;
            // cout<<c<<" "<<i<<endl;
            if(c<=temp)
            {
                if(c==temp)res=max(res,i);
                else
                {
                    res=i;
                    temp=c;
                }
            }
        }
        return res;
    }
};
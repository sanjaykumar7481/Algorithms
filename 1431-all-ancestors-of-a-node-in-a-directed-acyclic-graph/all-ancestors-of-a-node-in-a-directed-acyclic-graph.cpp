class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>Indegree(n,0);
        vector<int>adj[n];
        vector<vector<int>>temp(n,vector<int>(n,0));
        for(auto i:edges)
        {
            Indegree[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(Indegree[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int par=q.front();
            q.pop();
            for(auto i:adj[par])
            {
                temp[i][par]=1;
                for(int j=0;j<n;j++)
                {
                    if(temp[par][j])temp[i][j]=1;
                }
                Indegree[i]--;
                if(Indegree[i]==0)q.push(i);
            }
        }
        vector<vector<int>>res(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                if(temp[i][j])res[i].push_back(j);
            }
        }
        return res;
    }
};
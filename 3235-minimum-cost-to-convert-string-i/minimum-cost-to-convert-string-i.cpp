class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>adj(26,vector<int>(26,1e9));
        for(int i=0;i<original.size();i++)
        {
            int x=original[i]-'a',y=changed[i]-'a';
            adj[x][y]=min(cost[i],adj[x][y]);
        }
        for(int i=0;i<26;i++)adj[i][i]=0;
        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(adj[i][k]==1e9 or adj[k][j]==1e9)continue;
                    if(adj[i][j]>adj[i][k]+adj[k][j])adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
        long long res=0;
        for(int i=0;i<source.size();i++)
        {
            if(adj[source[i]-'a'][target[i]-'a']==1e9)return -1;
            // cout<<adj[source[i]-'a'][target[i]-'a']<<" ";
            res+=adj[source[i]-'a'][target[i]-'a'];
        }
        return res;
    }
};
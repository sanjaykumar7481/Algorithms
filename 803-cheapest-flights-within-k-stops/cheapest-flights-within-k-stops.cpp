class Solution {
public:
    int fun(vector<vector<int>>adj[],int src,int dst,int k,vector<vector<int>>&dp)
    {
        if(k<0)return 1e8;
        if(dp[src][k]!=-1)return dp[src][k];
        if(src==dst)return 0;
        int ans=1e8;
        for(auto i:adj[src]){
            ans=min(ans,i[1]+fun(adj,i[0],dst,k-1,dp));
        }
        return dp[src][k]=ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>adj[n];
        vector<vector<int>>dp(n,vector<int>(k+2,-1));
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        int res=fun(adj,src,dst,k+1,dp);
        if(res>=1e8)return -1;
        return res;
    }
};
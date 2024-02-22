class Solution {
public:
    bool dfs(int i,vector<int>adj[],vector<int>&vis,vector<int>&temp,vector<int>&dp)
    {
        if(dp[i]!=-1)return dp[i];
        vis[i]=1;
        temp[i]=1;
        bool a=true;
        for(auto j:adj[i])
        {
            if(!temp[j])
            {
                a=a and dfs(j,adj,vis,temp,dp);
                if(!a)return dp[i]=a;
            }
            else return dp[i]=false;
        }
        temp[i]=0;
        return dp[i]=a;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto i:prerequisites)
        {
            adj[i[0]].push_back(i[1]);
        }
        vector<int>vis(numCourses,0),dp(numCourses,-1);
        bool res=true;
        for(int i=0;i<numCourses;i++)
        {
            vector<int>temp(numCourses,0);
            if(!vis[i])res=res and dfs(i,adj,vis,temp,dp);
        }
        // for(int i=0;i<numCourses;i++)if(vis[i])
        return res;
        
    }
};
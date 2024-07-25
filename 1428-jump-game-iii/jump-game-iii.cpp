int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class Solution {
public:
    bool dfs(int i,vector<int>&arr,vector<int>&vis,vector<bool>&dp)
    {
        if(i<0 or i>=arr.size() or vis[i])return false;
        if(dp[i]==true)return true;
        vis[i]=1;
        dp[i]=dfs(i+arr[i],arr,vis,dp) or dfs(i-arr[i],arr,vis,dp);
        return dp[i];
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool>dp(arr.size(),false);
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)dp[i]=true;
        }
        vector<int>vis(arr.size(),0);
        bool d=dfs(start,arr,vis,dp);
        // if(dp[start])return true;
        return dp[start];
    }
};
class Solution {
public:
    int fun(int i,int size,int n,vector<vector<int>>&dp){
        if(i==n)return 0;
        if(dp[i][size]!=-1)return dp[i][size];
        int ans=1e9;
        if(i+i<=n)ans=min(ans,2+fun(i+i,i,n,dp));
        if(size!=0 and i+size<=n)ans=min(ans,1+fun(i+size,size,n,dp));
        if(ans>1e9)ans=1e9;
        return dp[i][size]=ans;
    }
    int minSteps(int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(1,0,n,dp);
    }
};
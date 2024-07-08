class Solution {
public:
    int fun(int i,int n,vector<vector<int>>&dp)
    {
        if(i>n)return 1;
        if(dp[i][n]!=-1)return dp[i][n];
        int ans=0;
        for(int j=i;j<=n;j++)
        {
            int a=fun(j+1,n,dp);
            int b=fun(i,j-1,dp);
            ans+=a*b;
        }
        return dp[i][n]=ans;
    }
    int numTrees(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return fun(1,n,dp); 
    }
};
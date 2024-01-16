class Solution {
public:
    int fun(int n,vector<int>&dp)
    {
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=fun(n-1,dp)+fun(n-2,dp);
    }
    int fib(int n) {
        if(n<=0)return 0;
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        return fun(n,dp);
    }
};
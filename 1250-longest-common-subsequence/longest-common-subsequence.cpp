class Solution {
public:
    int fun(int i,int j,string &a,string &b,vector<vector<int>>&dp)
    {
        if(i>=a.size() or j>=b.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(a[i]==b[j])ans=max(ans,1+fun(i+1,j+1,a,b,dp));
        ans=max(ans,fun(i+1,j,a,b,dp));
        ans=max(ans,fun(i,j+1,a,b,dp));
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return fun(0,0,text1,text2,dp);
    }
};
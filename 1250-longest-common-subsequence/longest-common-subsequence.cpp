class Solution {
public:
    int fun(int i,int j,string &a,string &b,vector<vector<int>>&dp)
    {
        if(i>=a.size() or j>=b.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(a[i]==b[j])return 1+fun(i+1,j+1,a,b,dp);
        ans=max(ans,fun(i+1,j,a,b,dp));
        ans=max(ans,fun(i,j+1,a,b,dp));
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=text1.size()-1;i>=0;i--)
        {
            for(int j=text2.size()-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                }
                dp[i][j]=max(dp[i][j],max(dp[i+1][j],dp[i][j+1]));
            }
        }
        return dp[0][0];
    }
};
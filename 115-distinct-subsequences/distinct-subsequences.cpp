class Solution {
public:
    int fun(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    {
        if(j>=t.size())return 1;
        if(i>=s.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j])
        {
            return dp[i][j]=fun(i+1,j+1,s,t,dp)+fun(i+1,j,s,t,dp);
        }
        return dp[i][j]=fun(i+1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
        long long mod=1e9+7;
        for(int i=0;i<=s.size();i++)dp[i][t.size()]=1;
        for(int i=s.size()-1;i>=0;i--)
        {
            for(int j=t.size()-1;j>=0;j--)
            {
                if(s[i]==t[j])
                {
                    dp[i][j]=(dp[i+1][j+1]%mod + dp[i+1][j]%mod)%mod;
                }
                else dp[i][j]=dp[i+1][j];
            }
        }
        // for(int i=0;i<s.size();i++)cout<<dp[i][0]<<" ";
        return dp[0][0];
        // return fun(0,0,s,t,dp);
    }
};
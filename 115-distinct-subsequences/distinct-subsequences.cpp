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
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return fun(0,0,s,t,dp);
    }
};
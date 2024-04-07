class Solution {
public:
    bool fun(int i,string &s,int t,vector<vector<int>>&dp)
    {
        if(i>=s.size())return t==0;
        bool res=false;
        if(dp[i][t]!=-1)return dp[i][t];
        if(s[i]=='*')
        {
            res=res or fun(i+1,s,t,dp) or fun(i+1,s,t+1,dp);
            if(t>0)res=res or fun(i+1,s,t-1,dp);
        }
        else{
            if(s[i]=='(')res=res or fun(i+1,s,t+1,dp);
            else if(t>0)res=res or fun(i+1,s,t-1,dp);
            else return false;
        }
        return dp[i][t]=res;
    }
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return fun(0,s,0,dp);
    }
};
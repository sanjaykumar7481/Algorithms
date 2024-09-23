class Solution {
public:
    unordered_map<string,int>mp;
    int fun(int i,string &s,vector<int>&dp)
    {
        if(i==s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        string p;
        int ans=1e9;
        for(int j=i;j<s.size();j++)
        {
            p+=s[j];
            if(mp.find(p)!=mp.end())
            {
                ans=min(fun(j+1,s,dp),ans);
            }
            ans=min((j-i+1)+fun(j+1,s,dp),ans);
        }
        if(ans>1e9)ans=1e9;
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto i:dictionary)mp[i]=0;
        vector<int>dp(s.size(),-1);
        return fun(0,s,dp);
    }
};
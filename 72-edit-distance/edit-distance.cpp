class Solution {
public:
    int fun(int i,int j,string &a,string &b,vector<vector<int>>&dp)
    {
        if(i>=a.size())return b.size()-j;
        if(j>=b.size())return a.size()-i;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        if(a[i]==b[j])return fun(i+1,j+1,a,b,dp);
        ans=min(ans,1+fun(i+1,j,a,b,dp));//inser
        ans=min(ans,1+fun(i,j+1,a,b,dp));//del
        ans=min(ans,1+fun(i+1,j+1,a,b,dp));//replace
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        // if(word1=="")return word2.size();
        vector<vector<int>>dp(word2.size(),vector<int>(word1.size(),-1));
        return fun(0,0,word2,word1,dp);
    }
};
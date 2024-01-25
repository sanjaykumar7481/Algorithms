class Solution {
public:
    int fun(int i,int j,string &text1,string &text2,vector<vector<int>>&dp)
    {
        if(i==text1.size() or j==text2.size())
        {
            // cout<<temp<<" ";
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(text1[i]==text2[j])
        {
              ans=1+fun(i+1,j+1,text1,text2,dp);
        }
        int np1=0,np2=0;
            np1= fun(i+1,j,text1,text2,dp);
              np2=fun(i,j+1,text1,text2,dp);
        return dp[i][j]=max(ans,max(np1,np2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return fun(0,0,text1,text2,dp);
    }
};
class Solution {
public:
    int fun(int i,int j,int n,string &ring,string &key,vector<vector<int>>&dp)
    {
        if(j==key.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int res=1e9;
        for(int p=0;p<n;p++)
        {
            if(ring[p]==key[j])
            {
                int k=abs(i-p);
                int temp=min(k+1,abs(n-k)+1);
                res=min(res,temp+fun(p,j+1,n,ring,key,dp));
            }
        }
        return dp[i][j]=res;
    }
    int findRotateSteps(string ring, string key) {
        vector<vector<int>>dp(ring.size(),vector<int>(key.size(),-1));
      return fun(0,0,ring.size(),ring,key,dp);  
    }
};
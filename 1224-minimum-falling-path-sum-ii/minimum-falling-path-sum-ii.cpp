class Solution {
public:
    int fun(int i,int j,int pre,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(j<0 or j>=grid.size())return 1e9;
        if(i==grid.size()-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int res=1e9;
        for(int p=0;p<grid.size();p++)
        {
            if(p!=j)res=min(res,fun(i+1,p,pre,grid,dp));
        }
        return dp[i][j]=res+grid[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int res=INT_MAX;
        vector<vector<int>>dp(grid.size(),vector<int>(grid.size(),-1));
        for(int i=0;i<grid.size();i++)
        {
            res=min(res,fun(0,i,-1,grid,dp));
        }
        return res;
    }
};
class Solution {
public:
    int fun(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(dp[row][col]!=-1)return dp[row][col];
        int max_ans=0;
        if(row>0 and col<grid[0].size()-1 and grid[row][col]<grid[row-1][col+1])
            max_ans=max(max_ans,1+fun(row-1,col+1,grid,dp));
        if(row<grid.size()-1 and col<grid[0].size()-1 and grid[row][col]<grid[row+1][col+1])
            max_ans=max(max_ans,1+fun(row+1,col+1,grid,dp));
        if(col<grid[0].size()-1 and grid[row][col]<grid[row][col+1])
            max_ans=max(max_ans,1+fun(row,col+1,grid,dp));
        return dp[row][col]=max_ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++)
        {
            ans=max(ans,fun(i,0,grid,dp)); 
        }
        return ans;
    }
};
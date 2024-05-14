class Solution {
public:
    int fun(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or vis[i][j] or grid[i][j]==0)return 0;
        vis[i][j]=1;
        int ans=0;
        ans=max(ans,grid[i][j]+fun(i+1,j,grid,vis));
        ans=max(ans,grid[i][j]+fun(i-1,j,grid,vis));
        ans=max(ans,grid[i][j]+fun(i,j-1,grid,vis));
        ans=max(ans,grid[i][j]+fun(i,j+1,grid,vis));
        vis[i][j]=0;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0)),temp;
        temp=vis;
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j])
                {
                    vis=temp;
                    ans=max(ans,fun(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
};
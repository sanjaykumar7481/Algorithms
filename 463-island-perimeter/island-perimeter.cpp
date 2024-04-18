class Solution {
public:
    int fun(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)return 1;
        if(vis[i][j])return 0;
        vis[i][j]=1;
        return fun(i+1,j,grid,vis)+fun(i-1,j,grid,vis)+fun(i,j+1,grid,vis)+fun(i,j-1,grid,vis);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])return fun(i,j,grid,vis);
            }
        }
        return 0;
    }
};
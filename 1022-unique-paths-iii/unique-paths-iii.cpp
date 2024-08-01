class Solution {
public:
    int fun(int i,int j,vector<vector<int>>&grid,int c,vector<vector<int>>&vis)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==-1 or vis[i][j])return 0;
        if(grid[i][j]==2)
        {
            return c==0;
        }
        vis[i][j]=1;
        int ans=0;
        ans+=fun(i+1,j,grid,c-1,vis);
        ans+=fun(i-1,j,grid,c-1,vis);
        ans+=fun(i,j-1,grid,c-1,vis);
        ans+=fun(i,j+1,grid,c-1,vis);
        vis[i][j]=0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int c=0;
        int sti,stj;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==0)c++;
                if(grid[i][j]==1)
                {
                    sti=i;
                    stj=j;
                }
            }
        }
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        return fun(sti,stj,grid,c+1,vis);
    }
};
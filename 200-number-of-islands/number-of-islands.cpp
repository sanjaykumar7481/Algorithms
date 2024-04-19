class Solution {
public:
    int dfs(int r,int c,int rs,int cs,vector<vector<int>>&v,vector<vector<char>>&grid)
    {
        if(r<0 or c<0 or r>=rs or c>=cs or grid[r][c]=='0' or v[r][c]==1)
            return 0;
        v[r][c]=1;
        dfs(r-1,c,rs,cs,v,grid);
        dfs(r+1,c,rs,cs,v,grid);
        dfs(r,c-1,rs,cs,v,grid);
        dfs(r,c+1,rs,cs,v,grid);
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        int rs=grid.size();
        int cs=grid[0].size();
        vector<vector<int>>v(rs,vector<int>(cs,0));
        for(int i=0;i<rs;i++)
        {
            for(int j=0;j<cs;j++)
            {
                if(grid[i][j]!='0')
                    c+=dfs(i,j,rs,cs,v,grid);
            }
        }
        return c;
    }
};
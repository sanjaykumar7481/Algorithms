class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            if(grid[i][0]==1)continue;
            for(int j=0;j<grid[0].size();j++)
            {
                grid[i][j]=not grid[i][j];
            }
        }
        for(int j=1;j<grid[0].size();j++)
        {
            int one=0,zero=0;
            for(int i=0;i<grid.size();i++)
            {
                if(grid[i][j])one++;
                else zero++;
            }
            if(zero>one)
            {
                for(int i=0;i<grid.size();i++)grid[i][j]=not grid[i][j];
            }
        }
        int res=0;
        for(int i=0;i<grid.size();i++)
        {
            int ans=0,n=grid[i].size();
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j])ans|=(1<<(n-j-1));
            }
            res+=ans;
        }
        return res;
    }
};
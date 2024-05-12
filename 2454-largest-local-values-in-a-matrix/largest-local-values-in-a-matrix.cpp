class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>>res(grid.size()-2,vector<int>(grid.size()-2));
        for(int i=0;i<grid.size()-2;i++)
        {
            for(int j=0;j<grid.size()-2;j++)
            {
                int maxi=-1;
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                        maxi=max(maxi,grid[k][l]);
                    }
                }
                res[i][j]=maxi;
            }
        }
        return res;
    }
};
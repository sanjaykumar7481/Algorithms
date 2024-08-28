class Solution {
public:
    bool fun(int i,int j,vector<vector<int>>&a,vector<vector<int>>&b,vector<vector<int>>&vis)
    {
        if(i<0 or j<0 or i>=a.size() or j>=a[0].size() or vis[i][j] or b[i][j]==0)return true;
        if(b[i][j] and !a[i][j])return false;
        vis[i][j]=1;
        bool a1=fun(i+1,j,a,b,vis);
        bool a2=fun(i-1,j,a,b,vis);
        bool a3=fun(i,j+1,a,b,vis);
        bool a4=fun(i,j-1,a,b,vis);
        return a1 and a2 and a3 and a4;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int c=0;
        vector<vector<int>>vis(grid1.size(),vector<int>(grid1[0].size(),0));
        for(int i=0;i<grid1.size();i++)
        {
            for(int j=0;j<grid1[0].size();j++)
            {
                if(grid1[i][j] and grid2[i][j] and !vis[i][j])
                {
                    if(fun(i,j,grid1,grid2,vis))c++;
                }
            }
        }
        return c;
    }
};
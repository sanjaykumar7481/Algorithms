class Solution {
public:
    int fun(int i,int j,vector<vector<int>>&land,vector<vector<int>>&vis,vector<int>&res)
    {
        if(i<0 or j<0 or i>=land.size() or j>=land[0].size() or land[i][j]==0)return 0;
        if(vis[i][j])return -1;
        vis[i][j]=1;
        int a=fun(i-1,j,land,vis,res);
        int b=fun(i,j-1,land,vis,res);
        int c=fun(i+1,j,land,vis,res);
        int d=fun(i,j+1,land,vis,res);
        if(a==0 and b==0)
        {
            res[0]=i;
            res[1]=j;
        }
        if(c==0 and d==0)
        {
            res[2]=i;
            res[3]=j;
        }
        return 1;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>vis(land.size(),vector<int>(land[0].size(),0));
        vector<vector<int>>res;
        for(int i=0;i<land.size();i++)
        {
            for(int j=0;j<land[0].size();j++)
            {
                if(vis[i][j]==0 and land[i][j]==1)
                {
                    vector<int>temp(4);
                    int c=fun(i,j,land,vis,temp);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
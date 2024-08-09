class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i+2<grid.size();i++){
            for(int j=0;j+2<grid[0].size();j++)
            {
                int c1=grid[i][j]+grid[i+1][j]+grid[i+2][j];
                int temp=c1;
                int c2=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
                if(temp!=c2)continue;
                int c3=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
                if(temp!=c3)continue;
                int r1=grid[i][j]+grid[i][j+1]+grid[i][j+2];
                if(temp!=r1)continue;
                int r2=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
                if(temp!=r2)continue;
                int r3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                if(temp!=r3)continue;
                int d1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                if(temp!=d1)continue;
                int d2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
                if(temp!=d2)continue;
                int arr[10]={0};
                bool f=true;
                for(int k=i;k<i+3;k++)
                {
                    for(int p=j;p<j+3;p++)
                    {
                        if(grid[k][p]>9 or grid[k][p]<1){
                            f=false;
                            break;
                        }
                        if(arr[grid[k][p]]>1)
                        {
                            f=false;
                            break;
                        }
                        arr[grid[k][p]]++;
                    }
                }
                if(f)ans++;
            }
        }
        return ans;
    }
};
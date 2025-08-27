class Solution {
    public boolean valid(int i,int j,int[][] grid){
        return i>=0 && i<grid.length && j>=0 && j<grid[0].length;
    }
    public int fun(int i,int j,int[][] dir,int k,int flag,int[][] grid,int target){
        if(grid[i][j]!=target)return 0;
        int ans=0,t=0;
        if(valid(i+dir[k][0],j+dir[k][1],grid))
            ans=1+fun(i+dir[k][0],j+dir[k][1],dir,k,flag,grid,target==2?0:2);
        if(flag==1){
            k=(k+1)%4;
            if(valid(i+dir[k][0],j+dir[k][1],grid))
            ans=Math.max(ans,1+fun(i+dir[k][0],j+dir[k][1],dir,k,0,grid,target==2?0:2));
        }
        ans=Math.max(ans,1);
        return ans;

    }
    public int lenOfVDiagonal(int[][] grid) {
        int[][] dir=new int[4][2];
        dir[0]=new int[]{1,1};
        dir[1]=new int[]{1,-1};
        dir[2]=new int[]{-1,-1};
        dir[3]=new int[]{-1,1};
        int ans=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]!=1)continue;
                for(int k=0;k<4;k++)
                {
                    if(valid(i+dir[k][0],j+dir[k][1],grid) && grid[i+dir[k][0]][j+dir[k][1]]==2)
                    {
                        ans=Math.max(ans,1+fun(i+dir[k][0],j+dir[k][1],dir,k,1,grid,2));
                    }
                }
                ans=Math.max(ans,1);
                
            }
        }
        return ans;
    }
}
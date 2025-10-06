class Solution {
    private boolean valid(int i,int j,int n){
        if(i<0 || j<0 || i==n || j==n)return false;
        return true;
    }
    public int swimInWater(int[][] grid) {
        PriorityQueue<int[]>pq=new PriorityQueue<>((a,b)->a[0]-b[0]);
        pq.add(new int[]{grid[0][0],0,0});
        int[][] dist=new int[grid.length][grid[0].length];
        
        for(int i=0;i<grid.length;i++)Arrays.fill(dist[i],Integer.MAX_VALUE);
        dist[0][0]=grid[0][0];
        int[] dr=new int[]{1,-1,0,0};
        int[] dc=new int[]{0,0,1,-1};
        while(!pq.isEmpty()){
            int[] top=pq.poll();
            for(int i=0;i<4;i++){
                int r=top[1]+dr[i],c=top[2]+dc[i];
                if(valid(r,c,grid.length) && dist[r][c]>Math.max(top[0],grid[r][c])){
                    dist[r][c]=Math.max(top[0],grid[r][c]);
                    pq.add(new int[]{Math.max(top[0],grid[r][c]),r,c});
                }
            }

        }
        return dist[grid.length-1][grid.length-1];
    }
}
class Solution {
    static int find_par(int node,int[] par)
    {
        if(par[node]==node)return node;
        par[node]=find_par(par[node],par);
        return par[node];
    }
    public int[] findRedundantConnection(int[][] edges) {
        int[] res=new int[2];
        int[] par=new int[edges.length+1];
        for(int i=1;i<par.length;i++)par[i]=i;
        for(int i=0;i<edges.length;i++)
        {
            int par1=find_par(edges[i][0],par);
            int par2=find_par(edges[i][1],par);
            if(par1==par2)res=edges[i];
            else{
                par[par2]=par1;
            }
        }
        return res;

    }
}
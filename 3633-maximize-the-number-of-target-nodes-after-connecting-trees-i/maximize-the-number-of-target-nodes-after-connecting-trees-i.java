class Solution {
    private int findTarget(int st,ArrayList<Integer>[] adj,int k)
    {
        int ans=1;
        boolean [] vis=new boolean[adj.length];
        Queue<Integer>queue=new LinkedList<>();
        queue.add(st);
        while(!queue.isEmpty() && k>0)
        {
            int n=queue.size();
            for(int i=0;i<n;i++){
                int par=queue.poll();
                vis[par]=true;

                for(int j:adj[par])
                {
                    if(vis[j]==false){
                        ans++;
                        queue.add(j);
                    }
                }
            }
            k--;
        }
        return ans;
    }
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        ArrayList<Integer>[] adj1=new ArrayList[edges1.length+1];
        ArrayList<Integer>[] adj2=new ArrayList[edges2.length+1];

        for(int i=0;i<=edges1.length;i++){
            adj1[i]=new ArrayList<Integer>();
        }
        
        for(int i=0;i<=edges2.length;i++){
            adj2[i]=new ArrayList<Integer>();
        }

        for(int[] i:edges1){
            adj1[i[0]].add(i[1]);
            adj1[i[1]].add(i[0]);
        }

        for(int[] i:edges2){
            adj2[i[0]].add(i[1]);
            adj2[i[1]].add(i[0]);
        }

        int res[]=new int[edges1.length+1];
        int maxi=0;
        for(int i=0;i<=edges2.length;i++){
            maxi=Math.max(maxi,findTarget(i,adj2,k-1));
        }
        System.out.println(maxi);
        for(int i=0;i<=edges1.length;i++)
        {
            if(k==0)res[i]=1;
            else res[i]=findTarget(i,adj1,k)+maxi;
        }
        return res;
    }
}
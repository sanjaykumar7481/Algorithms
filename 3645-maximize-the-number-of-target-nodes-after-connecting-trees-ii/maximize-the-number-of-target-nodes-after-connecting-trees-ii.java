class Solution {
    private int[] findTarget(ArrayList<Integer>[] adj,boolean[] evenLevel)
    {
        int[] levelCount=new int[2];
        int ans=0;
        boolean [] vis=new boolean[adj.length];
        Queue<Integer>queue=new LinkedList<>();
        queue.add(0);
        while(!queue.isEmpty() )
        {
            
            int n=queue.size();
            for(int i=0;i<n;i++){
                int par=queue.poll();
                if(ans==0)evenLevel[par]=true;
                levelCount[ans]++;
                vis[par]=true;

                for(int j:adj[par])
                {
                    if(vis[j]==false){
                        
                        queue.add(j);
                    }
                }
            }
            ans^=1;
        }
        return levelCount;
    }
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2) {
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
        boolean [] evenLevel=new boolean[adj1.length];
        boolean [] temp=new boolean[adj2.length];
        int[] Tree1=findTarget(adj1,evenLevel);
        int[] Tree2=findTarget(adj2,temp);
        System.out.println(Tree1[0]+" "+Tree1[1]);
        System.out.println(Tree2[0]+" "+Tree2[1]);

        int res[]=new int[edges1.length+1];

        for(int i=0;i<=edges1.length;i++){
            res[i]+=evenLevel[i]?Tree1[0]:Tree1[1];
            res[i]+=Math.max(Tree2[0],Tree2[1]);
        }
        return res;


    }
}
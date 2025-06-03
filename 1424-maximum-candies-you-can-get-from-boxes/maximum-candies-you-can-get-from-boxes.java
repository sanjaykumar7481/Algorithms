class Solution {
    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        Queue<Integer>queue=new LinkedList<>();
        boolean[] visited=new boolean[status.length];
        boolean[] containsBox=new boolean[status.length];
        boolean[] keysFound=new boolean[status.length];
        for(int i:initialBoxes)
        {
            if(status[i]!=0)
            {
                visited[i]=true;
                queue.add(i);
            }
            containsBox[i]=true;
        }
        int ans=0;
        while(!queue.isEmpty()){
            int cur=queue.poll();
            System.out.println(cur);
            ans+=candies[cur];
            for(int i:keys[cur])
            {
                keysFound[i]=true;
                if(containsBox[i] && !visited[i])
                {
                    visited[i]=true;
                    queue.add(i);
                }
            }
            for(int i:containedBoxes[cur]){
                containsBox[i]=true;
                if((status[i]!=0 || keysFound[i]) && !visited[i])
                {
                    visited[i]=true;
                    queue.add(i);
                }
            }
        }
        return ans;
    }
}
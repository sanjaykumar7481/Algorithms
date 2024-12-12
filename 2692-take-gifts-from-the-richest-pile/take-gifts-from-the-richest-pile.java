class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq=new PriorityQueue<>((a,b)->b-a); 
        for(int i:gifts)pq.add(i);
        long res=0;
        for(int i=0;i<k;i++)
        {
            int t=pq.poll();
            pq.add((int)Math.sqrt(t));
        }
        while(!pq.isEmpty())res+=pq.poll();
        return res;
    }
}
class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        List<Integer>prefix=new ArrayList<>();
        int pre=0;
        for(int i=0;i<startTime.length;i++){
            prefix.add(startTime[i]-pre);
            pre=endTime[i];
        }
        prefix.add(eventTime-endTime[endTime.length-1]);
        for(int i=1;i<prefix.size();i++){
            prefix.set(i,prefix.get(i-1)+prefix.get(i));
        }
        int j=0,ans=0;
        for(int i=k;i<prefix.size();i++){
            if(j>0)ans=Math.max(prefix.get(i)-prefix.get(j-1),ans);
            else ans=Math.max(ans,prefix.get(i));
            j++;
        }
        return ans;
    }
}
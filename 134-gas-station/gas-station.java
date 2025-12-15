class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int totalGas=0,startIndex=-1;
        int[] pref=new int[gas.length];
        for(int start=0;start<gas.length;start++){
            totalGas+=gas[start]-cost[start];
            pref[start]=((start-1>=0) ?pref[start-1]:0)  + (gas[start]-cost[start]);
            if(totalGas<0){
                startIndex=-1;
                totalGas=0;
            }
            else if(startIndex==-1)startIndex=start;
        }
        if(startIndex==-1)return -1;
        int prev=startIndex>0?pref[startIndex-1]:0;
        // for(int i=0;i<gas.length;i++)
        // System.out.println(pref[i]);
        return totalGas+prev>=0 ? startIndex:-1;
    }
}
class Solution {
    public int minDominoRotations(int[] tops, int[] bottoms) {
        int ans=Integer.MAX_VALUE;
        int top_value=tops[0],top_count=1,bottom_count=0;
        int bottom_value=bottoms[0],i=1;
        while(i<tops.length && (tops[i]==top_value || bottoms[i]==top_value))
        {
            if(tops[i]==top_value)top_count++;
            if(bottoms[i]==top_value)bottom_count++;
            i++;
        }
        if(i==tops.length)ans=Math.min(ans,Math.min(tops.length-top_count,bottoms.length-bottom_count));
        top_count=0;
        bottom_count=1;
        i=1;
        while(i<tops.length && (tops[i]==bottom_value || bottoms[i]==bottom_value))
        {
            if(tops[i]==bottom_value)top_count++;
            if(bottoms[i]==bottom_value)bottom_count++;
            i++;
        }
        if(i==tops.length)ans=Math.min(ans,Math.min(tops.length-top_count,bottoms.length-bottom_count));
        if(ans==Integer.MAX_VALUE)return -1;
        return ans;
    }
}
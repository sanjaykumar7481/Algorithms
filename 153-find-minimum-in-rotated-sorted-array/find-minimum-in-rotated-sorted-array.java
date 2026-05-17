class Solution {
    public int findMin(int[] arr) {
        int l=0,r=arr.length-1;
        int min=Integer.MAX_VALUE;
        while(l<=r){
            int m=(l+r)/2;
            if(arr[m]>arr[r])l=m+1;
            else{
                min=Math.min(min,arr[m]);
                r=m-1;
            }
        }
        return min;
    }
}
class Solution {
    public int minimumDeletions(int[] nums) {
        int minIndex=0,maxIndex=0;
        int min=Integer.MAX_VALUE,max=Integer.MIN_VALUE;
        int minDeletions=nums.length;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>max){
                max=nums[i];
                maxIndex=i;
            }
            if(nums[i]<min){
                min=nums[i];
                minIndex=i;
            }
        }
        int left=Math.min(minIndex,maxIndex);
        int right=Math.max(minIndex,maxIndex);
        minDeletions=Math.min(right+1,nums.length-left);
        return Math.min(minDeletions,left+1+nums.length-right);

    }
}
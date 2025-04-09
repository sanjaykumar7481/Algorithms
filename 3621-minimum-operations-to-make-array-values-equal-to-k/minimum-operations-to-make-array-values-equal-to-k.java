class Solution {
    public int minOperations(int[] nums, int k) {
        Arrays.sort(nums);
        if(nums[0] < k) return -1;
        int c = 0, cur = nums[0];
        if(nums[0]>k)c++;
        for(int i=1;i<nums.length;i++){
            if(nums[i]!=cur){
                if(nums[i]>k)c++;
                cur=nums[i];
            }
        }
        return c;
    }
}
class Solution {
    public boolean check(int[] nums) {
        boolean flag=false;
        for(int i=0;i<nums.length-1;i++)
        {
            if(flag && (nums[0]<nums[i] || nums[i]>nums[i+1]))return false;
            if(nums[i]>nums[i+1])
            {
                flag=true;
            }
        }
        if(flag && nums[0]<nums[nums.length-1])return false;
        return true;
    }
}
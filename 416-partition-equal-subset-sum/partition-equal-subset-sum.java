class Solution {
    public boolean findSum(int st,int[] nums,int targetSum,int[][] dp){
        if(targetSum==0)return true;
        if(targetSum<0 || st==nums.length)return false;
        if(dp[st][targetSum]!=-1)return dp[st][targetSum]==1;
        if(findSum(st+1,nums,targetSum-nums[st],dp) || findSum(st+1,nums,targetSum,dp)){
            dp[st][targetSum]=1;
            return true;
        }
        else dp[st][targetSum]=0;
        return false;
    }
    public boolean canPartition(int[] nums) {
        int targetSum=0;
        for(int i=0;i<nums.length;i++)targetSum+=nums[i];
        if(targetSum%2==1)return false;
        int[][] dp=new int[nums.length][targetSum/2 +1];
        for(int i=0;i<nums.length;i++)
        {
            Arrays.fill(dp[i],-1);
        }
        return findSum(0,nums,targetSum/2,dp);
    }
}
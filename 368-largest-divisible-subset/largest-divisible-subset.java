class Solution {
    public int fun(int i,int[] nums,int[] dp,int[] pos){
        if(i>=nums.length)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        pos[i]=-1;
        for(int j=i+1;j<nums.length;j++){
            if(nums[j]%nums[i]==0){
                int temp=1+fun(j,nums,dp,pos);
                if(ans<temp){
                    ans=temp;
                    pos[i]=j;
                }
            }
        }
        return dp[i]=ans;
    }
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        List<Integer>res=new ArrayList<>();
        int[] dp=new int[nums.length];
        int[] pos=new int[nums.length];
        Arrays.fill(dp,-1);
        int ans=0,ind=0;
        for(int i=0;i<nums.length;i++){
            dp[i]=1+fun(i,nums,dp,pos);
            if(ans<dp[i]){
                ans=dp[i];
                ind=i;
            }
        }
        while(ind!=-1){
            res.add(nums[ind]);
            ind=pos[ind];
        }
        // System.out.println(ans);
        return res;
    }
}
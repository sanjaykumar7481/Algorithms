class Solution {
    public int countCompleteSubarrays(int[] nums) {
        HashMap<Integer,Integer>totalMap=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            totalMap.put(nums[i],0);
        }
        int total_distinct=totalMap.size();
        // System.out.println(total_distinct);
        int i=0,ans=0;
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int j=0;j<nums.length;j++){
            mp.put(nums[j],mp.getOrDefault(nums[j],0)+1);

            while(i<=j && mp.size()==total_distinct){
                ans+=(nums.length-j);
                if(mp.get(nums[i])==1)mp.remove(nums[i]);
                else mp.put(nums[i],mp.get(nums[i])-1);
                i++;
            }
        }
        return ans;
    }
}
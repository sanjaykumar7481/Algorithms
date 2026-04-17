class Solution {
    private int reverse(int a){
        int r=0;
        while(a>0){
            r=r*10+a%10;
            a=a/10;
        }
        return r;
    }
    public int minMirrorPairDistance(int[] nums) {
        int minDistance=Integer.MAX_VALUE;
        Map<Integer,Integer>mp=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            int reversedNum=reverse(nums[i]);
            if(mp.containsKey(reversedNum)){
                if(nums[i]%10!=0)
                minDistance=Math.min(i-mp.get(reversedNum),minDistance);
            }
            while(nums[i]%10==0){
                nums[i]/=10;
            }
            mp.put(nums[i],i);
        }
        return minDistance==Integer.MAX_VALUE?-1:minDistance;
    }
}
class Solution {
    public boolean isTrionic(int[] nums) {
        int increasingSequence=0;
        boolean trionic=false;
        for(int i=0;i<nums.length-1;i++)
        {
            if(nums[i]<nums[i+1]){
                if(increasingSequence==2){
                    trionic=true;
                }
                else increasingSequence=1;
            }
            else if(nums[i]>nums[i+1]){
                if(trionic==true || increasingSequence==0)return false;
                if(increasingSequence==1)
                {
                    increasingSequence=2;
                    trionic=false;
                }
                
            }
            else return false;
        }
        return trionic;
    }
}
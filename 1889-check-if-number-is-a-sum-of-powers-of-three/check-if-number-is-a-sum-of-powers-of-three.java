class Solution {
    public boolean checkPowersOfThree(int n) {
        if(n==1)return true;
        int pow=0,temp=n,count=0;
        int val=1;
        while(temp!=0){
            temp/=3;
            count++;
            val*=3;
        }
        count--;
        val/=3;
        System.out.println(val);
        while(count>0)
        {
            if(n-val>=0){
                n-=val;
            }
            count--;
            val/=3;
        }
        return n<=1;
    }
}
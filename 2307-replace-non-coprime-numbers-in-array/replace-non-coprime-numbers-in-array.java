class Solution {
    private long GCD(long a,long b){
        if(b==0)return a;
        return GCD(b,a%b);
    }
    public List<Integer> replaceNonCoprimes(int[] nums) {
        Stack<Integer>st=new Stack<>();
        long head,top;
        for(int i=0;i<nums.length;i++)
        {
            top=nums[i];
            while(!st.isEmpty() && GCD(Math.max(top,st.peek()),Math.min(top,st.peek()))>1){
                head=st.pop();
                top=(top*head)/GCD(Math.max(top,head),Math.min(top,head));
                // System.out.println(top);
            }
            st.add((int)top);
        }
        return st;
    }
}
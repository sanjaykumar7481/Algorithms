class Solution {
    public int longestPalindrome(String[] words) {
        int ans=0;
        boolean flag=false;
        Map<String,Integer>counter=new HashMap<>();
        for(int i=0;i<words.length;i++){
            counter.put(words[i],counter.getOrDefault(words[i],0)+1);
        }
        
        for(String i:counter.keySet()){
            System.out.println(i+" "+counter.get(i));
            String temp=""+i.charAt(1)+i.charAt(0);
            if(counter.containsKey(temp))
            {
                if(!i.equals(temp))
                {
                    ans+=Math.min(counter.get(i),counter.get(temp))*4;
                    
                }
                else 
                {
                    ans+=(counter.get(i)/2)*8;
                    if(counter.get(i)%2==1)flag=true;
                }
            }
            System.out.println(ans);
        }
        
        if(flag)ans+=4;
        return ans/2;
    }
}
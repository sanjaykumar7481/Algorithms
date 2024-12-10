class Solution {
    public int maximumLength(String s) {
        Map<String,Integer>mp=new HashMap<>();
        int i=0,res=-1;
        String temp=String.valueOf(s.charAt(0));
        while(i<s.length()-1)
        {
            if(s.charAt(i)==s.charAt(i+1))
            {
                temp+=s.charAt(i+1);
            }
            else
            {
                String ran="";
                for(int x=0;x<temp.length();x++)
                {
                    ran+=String.valueOf(temp.charAt(0));
                    mp.put(ran,mp.getOrDefault(ran,0)+temp.length()-x);
                    if(mp.get(ran)>=3)
                    {
                        // System.out.println(ran+" "+mp.get(ran));
                        if(res<ran.length())res=ran.length();
                    }
                }
                temp=String.valueOf(s.charAt(i+1));
            }
            i++;
        }
        String ran="";
                for(int x=0;x<temp.length();x++)
                {
                    ran+=String.valueOf(temp.charAt(0));
                    mp.put(ran,mp.getOrDefault(ran,0)+temp.length()-x);
                    if(mp.get(ran)>=3)
                    {
                        // System.out.println(ran+" "+mp.get(ran));
                        if(res<ran.length())res=ran.length();
                    }
                }
        return res;
    }
}
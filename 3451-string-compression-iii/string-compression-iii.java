class Solution {
    public String compressedString(String word) {
        String res="";
        int i=0,count=1;
        while(i<word.length()-1)
        {
            if(word.charAt(i)==word.charAt(i+1))count++;
            else
            {
                int n=count/9;
                for(int j=0;j<n;j++){
                    res+="9"+word.charAt(i);
                }
                int rem=count%9;
                // System.out.println(count+" "+rem);
                if(rem>0)res+=String.valueOf(rem)+word.charAt(i);
                count=1;
            }
            i++;
        }
        char last=word.charAt(i);
        int n=count/9;
        for(int j=0;j<n;j++){
            res+="9"+last;
        }
        int rem=count%9;
        if(rem>0)res+=String.valueOf(rem)+last;
        return res;
    }
}
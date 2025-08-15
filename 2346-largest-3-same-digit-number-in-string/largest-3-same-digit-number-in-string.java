class Solution {
    public String largestGoodInteger(String num) {
        String res="";
        for(int i=0;i+2<num.length();i++){
            if(num.charAt(i)==num.charAt(i+1))
            {
                if(num.charAt(i+1)==num.charAt(i+2)){
                    String temp=""+num.charAt(i)+num.charAt(i)+num.charAt(i);
                    if(temp.compareTo(res)>0)res=temp;
                    i+=2;
                }
                else i++;
            }
            
        }
        return res;
    }
}
class Solution {

    private String repeat(String r,int c){
        String res="";
        for(int i=0;i<c;i++)res+=r;
        return res;
    }
    public String pushDominoes(String dominoes) {
        String res="",temp="";
        boolean left_exist=false,right_exist=false;
        int empty_count=0;
        for(int i=0;i<dominoes.length();i++){
            String L="L",R="R";
            if(dominoes.charAt(i)=='R')
            {
                if(right_exist)res+=repeat("R",empty_count);
                else res+=temp;
                empty_count=0;
                right_exist=true;
                res+="R";
                temp="";
            }
            else if(dominoes.charAt(i)=='L')
            {
                if(right_exist){
                    res+=repeat("R",empty_count/2);
                    if(empty_count%2==1)res+=".";
                    res+=repeat("L",empty_count/2);
                }
                else{
                    res+=repeat("L",empty_count);
                }
                temp="";
                empty_count=0;
                right_exist=false;
                res+="L";
                // System.out.println(res);
            }
            else{
                temp+=".";
                empty_count++;
                
            }
            
        }
        if(right_exist)res+=repeat("R",empty_count);
        else res+=temp;
        return res;
    }
    
}
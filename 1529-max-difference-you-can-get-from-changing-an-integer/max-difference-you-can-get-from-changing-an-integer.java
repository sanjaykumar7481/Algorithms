class Solution {
    public int maxDiff(int num) {
        int change1[]=new int[10];
        int change2[]=new int[10];
        for(int i=0;i<10;i++){
            change1[i]=i;
            change2[i]=i;
        }
        String a=String.valueOf(num);
        for(int i=0;i<a.length();i++){
            if(a.charAt(i)!='9')
            {
                change1[a.charAt(i)-'0']=9;
                break;
            }
        }
        if(a.charAt(0)!='1')change2[a.charAt(0)-'0']=1;
        else{
            for(int i=1;i<a.length();i++){
                if(a.charAt(i)-'1'>0){
                    change2[a.charAt(i)-'0']=0;
                    break;
                }
            }
        }
        int fin_a=0,fin_b=0,p=(int)Math.pow(10,a.length()-1);
        for(int i=0;i<a.length();i++)
        {
            fin_a+=p*change1[a.charAt(i)-'0'];
            fin_b+=p*change2[a.charAt(i)-'0'];
            p/=10;
        }
        return fin_a-fin_b;

        // return 1;
    }
}
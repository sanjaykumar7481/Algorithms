class Solution {
    public String answerString(String word, int numFriends) {
        if(numFriends==1)return word;
        int windowSize=word.length()-(numFriends-1);
        char lar='a';
        String res="";
        for(int i=0;i<word.length();i++)
        {
            if(lar-'a'<=word.charAt(i)-'a')lar=word.charAt(i);
            
        }
        for(int i=0;i<word.length();i++){
            if(word.charAt(i)==lar){
                int rem=numFriends-1-i;
                String temp;
                if(rem>0) temp=word.substring(i,word.length()-rem);
                else temp=word.substring(i);
                if(res.compareTo(temp)<0)res=temp;
                
            }
        }
        return res;
    }
}
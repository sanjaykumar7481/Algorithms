class Solution {
    public int minimumPushes(String word) {
        int ans=0,i=1;
        int length=word.length();
        while(length>=8){
            ans+=8*i;
            length-=8;
            i++;
        }
        ans+=length*i;
        return ans;
    }
}
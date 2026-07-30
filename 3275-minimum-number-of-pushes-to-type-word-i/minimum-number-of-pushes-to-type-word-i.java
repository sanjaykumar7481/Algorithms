class Solution {
    public int minimumPushes(String word) {
        int length=word.length()/8;
        
        return 4*(length*(length+1)) + (word.length()%8)*(length+1);
    }
}
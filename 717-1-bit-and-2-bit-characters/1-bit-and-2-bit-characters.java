class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        for(int i=0;i<bits.length-1;i++){
            if(bits[i]==0)continue;
            else if(i==bits.length-2)return false;
            else i++;
        }
        return true;
    }
}
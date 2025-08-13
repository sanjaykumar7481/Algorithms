class Solution {
    public boolean isPowerOfThree(int n) {
        double k=Math.log10(n)/(double)Math.log10(3);
        System.out.println(k);
        return k==(int)k;

    }
}
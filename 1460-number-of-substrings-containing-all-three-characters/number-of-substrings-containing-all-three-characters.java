class Solution {
    public boolean satisfy_condition(int[] arr){
        if(arr[0]*arr[1]*arr[2]>0)return true;
        return false;
    }
    public int numberOfSubstrings(String s) {
        int ans=0,i=0;
        int[] arr=new int[3];
        for(int j=0;j<s.length();j++){
            arr[s.charAt(j)-'a']++;
            while(i<j && satisfy_condition(arr))
            {
                ans+=s.length()-j;
                arr[s.charAt(i)-'a']--;
                i++;
            }
        }
        return ans;
    }
}
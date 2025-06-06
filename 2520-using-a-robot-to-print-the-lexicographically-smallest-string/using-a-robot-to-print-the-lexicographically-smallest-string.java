class Solution {
    public String robotWithString(String s) {
        int minBack[]=new int[s.length()+1];
        minBack[s.length()]=s.length();

        char mini='}';
        for(int i=s.length()-1;i>=0;i--){
            if(mini>=s.charAt(i)){
                mini=s.charAt(i);
                minBack[i]=i;
            }
            else{
                minBack[i]=minBack[i+1];
            }
        }
        Stack<Character>st=new Stack<>();
        int i=0;
        StringBuilder res = new StringBuilder();
        while(i<s.length()){
            int smallest=minBack[i];
            for(int j=i;j<=smallest;j++)st.add(s.charAt(j));
            char nextSmallest=smallest+1<s.length()?s.charAt(minBack[smallest+1]):'}';
            while(!st.isEmpty() && st.peek()<=nextSmallest)
            {
                res.append(st.peek());
                st.pop();
            }
            i=smallest+1;
        }
        while(!st.isEmpty()){
            res.append(st.peek());
            st.pop();
        }
        return res.toString();
    }
}
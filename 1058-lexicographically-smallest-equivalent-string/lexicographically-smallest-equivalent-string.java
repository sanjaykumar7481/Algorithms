class Solution {
    int find(char a,char[] par)
    {
        if(a!=par[a-'a'])return find(par[a-'a'],par);
        return a-'a';
    }
    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        char par[]=new char[26];
        for(int i=0;i<26;i++)par[i]=(char)('a'+i);
        for(int i=0;i<s1.length();i++){
            int a=find(s1.charAt(i),par);
            int b=find(s2.charAt(i),par);
            if(par[a]!=par[b])
            {
                if(par[a]-'a'< par[b]-'a')par[b]=par[a];
                else par[a]=par[b];
                // System.out.println(s1.charAt(i)+" "+s2.charAt(i));
            }
        }
        // for(int i=0;i<26;i++)System.out.print(par[i]+" ");
        // System.out.println()
        String res="";
        for(int i=0;i<baseStr.length();i++){
            res+=par[find(baseStr.charAt(i),par)];
        }
        return res;
    }
}
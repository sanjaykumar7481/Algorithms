class Solution {
public:
    bool vowel(char s)
    {
        s=tolower(s);
        return (s=='a' or s=='e' or s=='i' or s=='o' or s=='u');
    }
    bool halvesAreAlike(string s) {
        int a=s.size()/2,c=0,p=0;
        for(int i=0;i<a;i++)if(vowel(s[i]))c++;
        for(int i=a;i<s.size();i++)if(vowel(s[i]))p++;
        return c==p;
    }
};
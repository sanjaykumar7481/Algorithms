class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int a=0,b=0,res=0;
        string str;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' or s[i]=='b')
            {
                if(s[i]=='a')a=1;
                else b=1;
                str+=s[i];
            }
            else
            {
                if(a and b)
                {
                    stack<char>st,sec;
                    if(y>x)reverse(str.begin(),str.end());
                    int more=max(x,y),less=min(x,y);
                    int j=0;
                    while(j<str.size())
                    {
                        if(str[j]=='b' and !st.empty() and st.top()=='a')
                        {
                            st.pop();
                            res+=more;
                        }
                        else st.push(str[j]);
                        j++;
                    }
                    while(!st.empty())
                    {
                        if(st.top()=='b' and !sec.empty() and sec.top()=='a')
                        {
                            sec.pop();
                            res+=less;
                        }
                        else sec.push(st.top());
                        st.pop();
                    }
                    
                }
                a=0;
                b=0;
                str="";
            }
        }
        stack<char>st,sec;
        if(y>x)reverse(str.begin(),str.end());
        int more=max(x,y),less=min(x,y);
        int j=0;
        while(j<str.size())
        {
                if(str[j]=='b' and !st.empty() and st.top()=='a')
                {
                        st.pop();
                        res+=more;
                }
                else st.push(str[j]);
                j++;
        }
        while(!st.empty())
        {
                if(st.top()=='b' and !sec.empty() and sec.top()=='a')
                {
                        sec.pop();
                        res+=less;
                }
                else sec.push(st.top());
                st.pop();
        }
     return res;
    }
};
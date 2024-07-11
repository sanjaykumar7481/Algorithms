class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        string temp="",ans;
        int par=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(temp!="")
                {
                    if(par%2)reverse(temp.begin(),temp.end());
                    st.push(temp);
                }
                st.push("(");
                temp="";
                par++;
            }
            else if(s[i]==')')
            {
                string res;
                if(temp!="") {
                    if(par%2)reverse(temp.begin(),temp.end());
                    st.push(temp);
                }
                while(st.top()!="(")
                {
                    string t=st.top();
                    st.pop();
                    // reverse(t.begin(),t.end());
                    if(par%2==0)res=t+res;
                    else res+=t;
                }
                st.pop();
                // if(par%2==0)
                // reverse(res.begin(),res.end());
                st.push(res);
                temp="";
                par--;
            }
            else temp+=s[i];
        }
        if(temp!="")st.push(temp);
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
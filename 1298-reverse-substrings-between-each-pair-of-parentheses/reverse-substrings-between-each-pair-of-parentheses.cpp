class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        string temp="",ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(temp!="")st.push(temp);
                st.push("(");
                temp="";
            }
            else if(s[i]==')')
            {
                string res;
                if(temp!="")st.push(temp);
                while(st.top()!="(")
                {
                    string t=st.top();
                    st.pop();
                    reverse(t.begin(),t.end());
                    res+=t;
                }
                st.pop();
                st.push(res);
                temp="";
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
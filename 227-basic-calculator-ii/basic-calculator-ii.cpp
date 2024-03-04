class Solution {
public:
    int precedence(string t)
    {
        if(t=="*" or t=="/")return 2;
        if(t=="+" or t=="-")return 1;
        // cout<<t<<":";
        return 3;
    }
    int calculate(string s) {
        stack<string>st;
        vector<string>postfix;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')continue;
            string t;
            while(i<s.size() and s[i]!='+' and s[i]!='-' and s[i]!='*' and s[i]!='/')t+=s[i++];
            postfix.push_back(t);
            if(i<s.size() and (s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/'))
            {
                string p;
                p+=s[i];
                if(!st.empty())
                while(!st.empty() and precedence(p)<=precedence(st.top()))
                {
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(p);
            }
        }
        while(!st.empty()){
            postfix.push_back(st.top());
            st.pop();
        }
        // for(auto i:postfix)cout<<i<<" ";
        stack<int>eval;
        for(auto i:postfix)
        {
            if(i=="*" or i=="+" or i=="-" or i=="/")
            {
                auto a=eval.top();
                eval.pop();
                auto b=eval.top();
                eval.pop();
                if(i=="+")eval.push(a+b);
                if(i=="-")eval.push(b-a);
                if(i=="*")eval.push(a*b);
                if(i=="/")eval.push(b/a);
            }
            else eval.push(stoi(i));
        }
        return eval.top();
        return 0;
    }
};
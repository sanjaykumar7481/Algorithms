class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        string res;
        for(auto i:s)
        {
            if(st.empty())st.push(i);
            else
            {
                auto t=st.top();
                if(tolower(t)==tolower(i))
                {
                    if((isupper(t) and islower(i)) or (islower(t) and isupper(i)))st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
        }
        while(!st.empty())
        {
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};
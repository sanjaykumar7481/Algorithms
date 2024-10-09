class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(auto i:s)
        {
            if(i==')' and !st.empty() and st.top()=='(')st.pop();
            else st.push(i);
        }
        return st.size();
    }
};
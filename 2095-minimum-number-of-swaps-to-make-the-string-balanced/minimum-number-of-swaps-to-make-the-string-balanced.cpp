class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(auto i:s)
        {
            if(i==']' and !st.empty() and st.top()=='[')st.pop();
            else st.push(i);
        }
        int ans=st.size()/2;
        if(ans%2)return (ans+1)/2;
        return ans/2;
    }
};
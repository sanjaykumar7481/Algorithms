class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<char>st;
        int t=0;
        string res;
        for(auto i:s)
        {
            if(isalpha(i))st.push_back(i);
            else{
                if(i=='(')
                {
                    t++;
                    st.push_back(i);
                }
                else{
                    if(t>0)
                    {
                        t--;
                        st.push_back(i);
                    }
                    else continue;
                }
            }
            int j=0;
            while(t==0 and j<st.size())
            {
                res+=st[j++];
            }
            if(t==0)st.clear();
        }
        string temp;
        for(int i=st.size()-1;i>=0;i--)
        {
            if(t and st[i]=='(')
            {
                t--;
                continue;
            }
            temp+=st[i];
        }
        reverse(temp.begin(),temp.end());
        // cout<<res.size()+temp.size()<<endl;
        return res+temp;
    }
};
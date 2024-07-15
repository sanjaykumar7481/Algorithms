class Solution {
public:
    string countOfAtoms(string formula) {
        
        map<string,int>mp;
        stack<pair<string,int>>st;
        int i=0,n=formula.size();
        while(i<n)
        {
            int res=0;
            while(i<n and formula[i]-'0'>=0 and formula[i]-'0'<10)
            {
                res=res*10 + (formula[i]-'0');
                i++;
            }
            if(res)
            {
                if(st.top().first==")")
                {
                    st.pop();
                    vector<pair<string,int>>random;
                    while(st.top().first!="(")
                    {
                        // mp[st.top().first]+=st.top().second*res;
                        auto a=st.top();
                        st.pop();
                        random.push_back({a.first,a.second*res});
                    }
                    st.pop();
                    for(auto i:random)st.push(i);
                }
                else{
                    auto a=st.top();
                    st.pop();
                    // mp[a.first]+=a.second*res;
                    st.push({a.first,a.second*res});
                }
            }
            if(formula[i]=='(' or formula[i]==')')
            {
                string t="";
                t+=formula[i++];
                st.push({t,0});
            }
            else if(isupper(formula[i]))
            {
                string tp="";
                tp+=formula[i];
                i++;
                while(i<n and islower(formula[i]))tp+=formula[i++];
                // cout<<tp<<" ";
                st.push({tp,1});
            }
        }
        while(!st.empty())
        {
            if(st.top().second)
            mp[st.top().first]+=st.top().second;
            st.pop();
        }        
        string ans;
        for(auto i:mp){
            ans+=i.first;
            if(i.second>1)ans+=to_string(i.second);
        }
        // cout<<endl;
        return ans;
    }
};
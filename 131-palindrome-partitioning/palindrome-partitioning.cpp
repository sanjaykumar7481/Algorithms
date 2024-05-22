class Solution {
public:
    bool palindrome(string &t)
    {
        if(t=="")return false;
        string p=""+t;
        reverse(t.begin(),t.end());
        return t==p;
    }
    void fun(int i,string t,string &s,vector<string>&temp,vector<vector<string>>&result)
    {
        if(i>=s.size())
        {
            // for(auto i:temp)cout<<i<<" ";
            // cout<<endl;
            if(t=="")result.push_back(temp);
            return;
        }
        t+=s[i];
        fun(i+1,t,s,temp,result);
        if(palindrome(t))
        {
            temp.push_back(t);
            fun(i+1,"",s,temp,result);
            temp.pop_back();
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>temp;
        fun(0,"",s,temp,result);
        return result;
    }
};
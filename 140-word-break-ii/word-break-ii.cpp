class Solution {
public:
    void fun(int i,string &s,unordered_map<string,int>&mp,vector<string>&res,string t,string temp)
    {
        if(i==s.size())
        {
            if(t!="" and t[t.size()-1]==' ' and temp=="")
            {
                t.pop_back();
                res.push_back(t);
            }
            return;
        }
        temp+=s[i];
        string var=t;
        if(mp.find(temp)!=mp.end())
        {
            t+=temp+" ";
            fun(i+1,s,mp,res,t,"");
            t=var;
        }
        fun(i+1,s,mp,res,t,temp);
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>res;
        unordered_map<string,int>mp;
        for(auto i:wordDict)mp[i]=0;
        fun(0,s,mp,res,"","");
        return res;
    }
};
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp,mp2;
        string res;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                if(mp2.find(t[i])==mp2.end())
                {
                    mp[s[i]]=t[i];
                    mp2[t[i]]='s';
                    res+=t[i];
                }
                else return false;
            }
            else res+=mp[s[i]];
        }
        return res==t;
    }
};
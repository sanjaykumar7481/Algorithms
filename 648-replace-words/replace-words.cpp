class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int>mp;
        for(auto i:dictionary)mp[i]=0;
        string res,t;
        vector<string>temp;
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]==' '){
                temp.push_back(t);
                t="";
            }
            else t+=sentence[i];
        }
        temp.push_back(t);
        for(auto i:temp)
        {
            t="";
            for(int j=0;j<i.size();j++)
            {
                t+=i[j];
                if(mp.find(t)!=mp.end())
                {
                    res+=t;
                    t="";
                    break;
                }
            }
            res+=t+" ";
        }
        res.pop_back();
        return res;
    }
};
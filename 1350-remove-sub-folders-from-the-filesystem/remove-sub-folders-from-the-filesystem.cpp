class Trie{
    public:
        unordered_map<string,Trie*>map;
        bool end;
        Trie()
        {
            this->end=false;
        }
};
class Solution {
public:
    void dfs(Trie *start,string res,vector<string>&ans)
    {
        if(start->end)
        {
            ans.push_back(res);
            return;
        }
        for(auto i:start->map)
        {
            dfs(i.second,res+i.first,ans);
        }
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie *nn=new Trie();
        Trie *start=nn;
        vector<string>res;
        for(auto i:folder)
        {
            string temp="/";
            nn=start;
            for(int j=1;j<i.size();j++)
            {
                if(i[j]=='/')
                {
                    if(nn->map.find(temp)==nn->map.end())
                    {
                        nn->map[temp]=new Trie();
                    }
                    nn=nn->map[temp];
                    temp="/";
                }
                else temp+=i[j];
            }
            if(nn->map.find(temp)==nn->map.end())
            {
                nn->map[temp]=new Trie();
            }
            nn=nn->map[temp];
            nn->end=true;
        }
        dfs(start,"",res);
        return res;
        
    }
};
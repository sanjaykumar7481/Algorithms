class Trie{
    public:
        bool end;
        Trie *contain[26]={NULL};
        int words;
        Trie(){
            this->end=false;
            this->words=0;
        }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *nn=new Trie();
        for(auto i:words)
        {
            Trie *temp=nn;
            for(auto j:i)
            {
                if(temp->contain[j-'a']==NULL)
                {
                    temp->contain[j-'a']=new Trie();
                    temp=temp->contain[j-'a'];
                    temp->words++;
                }
                else
                {
                    temp=temp->contain[j-'a'];
                     temp->words++;
                }
            }
            temp->end=true;
        }
        vector<int>res(words.size());
        for(int i=0;i<words.size();i++)
        {
            Trie *temp=nn;
            for(auto j:words[i])
            {
                if(temp->contain[j-'a']!=NULL)
                {
                    temp=temp->contain[j-'a'];
                    res[i]+=temp->words;
                }
                else break;
            }
        }
        return res;
    }
};
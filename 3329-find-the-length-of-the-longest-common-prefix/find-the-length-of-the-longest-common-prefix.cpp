class Trie{
    public:
        bool end;
        Trie* contain[20]={NULL};
        Trie(){
            this->end=false;
        }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie *newTrie=new Trie();
        int res=0;
        // cout<<newTrie->contain[0]<<" ";
        for(auto i:arr1)
        {
            string k=to_string(i);
            Trie *temp=newTrie;
            for(auto j:k)
            {
                if(temp->contain[j-'0']!=NULL)
                {
                    temp=temp->contain[j-'0'];
                }
                else
                {
                    temp->contain[j-'0']=new Trie();
                    temp=temp->contain[j-'0'];
                }
            }
            temp->end=true;
        }
        for(auto i:arr2)
        {
            string k=to_string(i);
            int c=0;
            Trie *temp=newTrie;
            for(auto j:k)
            {
                if(temp->contain[j-'0']!=NULL)
                {
                    temp=temp->contain[j-'0'];
                    c++;
                }
                else{
                    res=max(res,c);
                    break;
                }
            }
            res=max(res,c);
        }
        return res;
    }
};
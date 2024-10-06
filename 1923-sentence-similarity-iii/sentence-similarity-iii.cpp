class Solution {
public:
    bool fun(int i,int j,vector<string>&a,vector<string>&b,int used)
    {
        if(i==a.size() and j==b.size())return true;
        if(i==a.size())return used!=2;
        if(j==b.size())return false;
        bool ans=false;
        if(a[i]==b[j])
        {
            if(used==1)
            ans=ans or fun(i+1,j+1,a,b,2);
            else ans=ans or fun(i+1,j+1,a,b,used);
        }
        if(used!=2)ans=ans or fun(i,j+1,a,b,1);
        return ans;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string>str,target;
        string temp;
        for(auto i:sentence1)
        {
            if(i==' ')
            {
                str.push_back(temp);
                temp="";
            }
            else temp+=i;
        }
        str.push_back(temp);
        temp="";
        for(auto i:sentence2)
        {
            if(i==' ')
            {
                target.push_back(temp);
                temp="";
            }
            else temp+=i;
        }
        target.push_back(temp);
        if(target.size()<str.size())swap(target,str);
        for(auto i:str)cout<<i<<" ";
        cout<<endl;
        for(auto i:target)cout<<i<<" ";
        cout<<endl;
        return fun(0,0,str,target,0);
        
    }
};
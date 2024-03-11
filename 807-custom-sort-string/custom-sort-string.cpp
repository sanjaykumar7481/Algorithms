class Solution {
public:
    string customSortString(string order, string s) {
        int k=1;
        vector<int>freq(26,100);
        for(auto i:order)freq[i-'a']=k++;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<s.size()-i-1;j++)
            {
                if(freq[s[j]-'a']>freq[s[j+1]-'a'])
                {
                    char temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
                }
            }
        }
        return s;
        
        
    }
};
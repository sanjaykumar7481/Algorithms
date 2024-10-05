class Solution {
public:
    bool exist(vector<int>&a,vector<int>&b)
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int>for_s1(26,0),for_s2(26,0);
        for(auto i:s1)for_s1[i-'a']++;
        int i=0,j=0;
        while(j<s2.size())
        {
            for_s2[s2[j]-'a']++;
            if(j-i+1==s1.size())
            {
                if(exist(for_s1,for_s2))return true;
                else{
                    for_s2[s2[i]-'a']--;
                    i++;
                }
            }
            j++;
        }
        return false;
    }
};
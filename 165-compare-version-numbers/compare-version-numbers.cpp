class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        int first=0,second=0;
        vector<int>for_version1,for_version2;
        while(i<version1.size() and j<version2.size())
        {
            if(version1[i]=='.')
            {
                for_version1.push_back(first);
                first=0;
            }
            else first=(first*10)+(version1[i]-'0');
            if(version2[j]=='.')
            {
                for_version2.push_back(second);
                second=0;
            }
            else second=(second*10)+(version2[j]-'0');
            i++;
            j++;
        }
        while(i<version1.size())
        {
            if(version1[i]=='.')
            {
                for_version1.push_back(first);
                first=0;
            }
            else first=(first*10)+(version1[i]-'0');
            i++;
        }
        for_version1.push_back(first);
        while(j<version2.size())
        {
            if(version2[j]=='.')
            {
                for_version2.push_back(second);
                second=0;
            }
            else second=(second*10)+(version2[j]-'0');
            j++;
        }
        for_version2.push_back(second);
        i=0;
        j=0;
        // for(auto a:for_version1)cout<<a<<" ";
        // cout<<endl;
        // for(auto b:for_version2)cout<<b<<" ";
        // cout<<endl;
        while(i<for_version1.size() and j<for_version2.size())
        {
            // cout<<for_version1[i]<<" "<<for_version2[j]<<endl;
            if(for_version1[i]>for_version2[j])return 1;
            if(for_version1[i]<for_version2[j])return -1;
            i++;
            j++;
        }
        while(i<for_version1.size())
        {
            if(for_version1[i]!=0)return 1;
            i++;
        }
        while(j<for_version2.size())
        {
            if(for_version2[j]!=0)return -1;
            j++;
        }
        return 0;
    }
};
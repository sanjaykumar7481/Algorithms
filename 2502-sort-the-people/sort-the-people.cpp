class Solution {
public:
    static const bool cmp(const pair<string,int>&a,const pair<string,int>&b)
    {
        return a.second>b.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>>temp;
        vector<string>res;
        for(int i=0;i<names.size();i++)temp.push_back({names[i],heights[i]});
        sort(temp.begin(),temp.end(),cmp);
        for(auto i:temp)res.push_back(i.first);
        return res;
    }
};
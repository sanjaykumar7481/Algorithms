class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(auto i:nums1)mp[i]=0;
        for(auto i:nums2)
        {
            if(mp.find(i)!=mp.end())
            {
                res.push_back(i);
                mp.erase(i);
            }
        }
        return res;
    }
};
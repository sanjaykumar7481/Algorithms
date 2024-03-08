class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int k=-1,c=0;
        for(auto i:nums)k=max(k,++mp[i]);
        for(auto i:mp)
        {
            if(i.second==k)c+=i.second;
        }
        return c;
    }
};
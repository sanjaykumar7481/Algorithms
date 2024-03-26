class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]=0;
        int i;
        for(i=1;i<=nums.size();i++)
        {
            if(mp.find(i)==mp.end())return i;
        }
        return i;
    }
};
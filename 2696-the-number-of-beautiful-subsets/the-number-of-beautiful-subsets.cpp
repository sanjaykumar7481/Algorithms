class Solution {
public:
    int res=0;
    void fun(int i,vector<int>&nums,int k,unordered_map<int,int>&mp)
    {
        if(i>=nums.size())
        {
            if(mp.size()>0)res++;
            return;
        }
        if(mp.find(nums[i]-k)==mp.end() and mp.find(nums[i]+k)==mp.end())
        {
            mp[nums[i]]++;
            fun(i+1,nums,k,mp);
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
        }
        fun(i+1,nums,k,mp);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        fun(0,nums,k,mp);
        return res;
    }
};
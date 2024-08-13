class Solution {
public:
    unordered_map<string,int>mp;
    void fun(int i,vector<int>&nums,int target, vector<vector<int>>&res,vector<int>&temp,string &s)
    {
        if(target==0)
        {
            // cout<<s<<" ";
            // mp[s]++;
            // if(mp[s]==1)
            // {
            res.push_back(temp);
            // }
            return;
        }
        if(i>=nums.size())return;
        int j=i;
        while(j<nums.size())
        {
            if(target-nums[j]>=0){
                temp.push_back(nums[j]);
                fun(j+1,nums,target-nums[j],res,temp,s);
                temp.pop_back();
            }
            else break;
            while(j+1<nums.size() and nums[j]==nums[j+1])j++;
            j++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>temp;
        string s;
        fun(0,candidates,target,res,temp,s);
        return res;
    }
};
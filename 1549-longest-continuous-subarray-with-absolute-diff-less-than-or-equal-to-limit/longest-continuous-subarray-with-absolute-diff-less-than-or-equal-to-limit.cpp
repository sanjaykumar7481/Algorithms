class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0,j=0,Min=INT_MAX,Max=0,mini=0,maxi=0,ans=0;
        map<int,queue<int>>mp;
        while(i<nums.size())
        {
            mp[nums[i]].push(i);
            if(Min>=nums[i])
            {
                mini=i;
                Min=nums[i];
            }
            if(Max<=nums[i])
            {
                maxi=i;
                Max=nums[i];
            }
            if(Max-Min>limit)
            {
                if(mini<maxi)
                {
                    // cout<<Min<<" "<<Max<<endl;
                    ans=max(ans,abs(j-maxi));
                    for(int k=j;k<=mini;k++)
                    {
                        mp[nums[k]].pop();
                        if(mp[nums[k]].empty())mp.erase(nums[k]);
                    }
                    j=mini+1;
                    Min=mp.begin()->first;
                    mini=mp.begin()->second.front();
                }
                else
                {
                    // cout<<Max<<" "<<Min<<endl;
                    ans=max(ans,abs(j-mini));
                    for(int k=j;k<=maxi;k++)
                    {
                        mp[nums[k]].pop();
                        if(mp[nums[k]].empty())mp.erase(nums[k]);
                    }
                    j=maxi+1;
                    Max=mp.rbegin()->first;
                    maxi=mp.rbegin()->second.front();
                }
            }
            i++;
        }
        int last=nums.size()-j;
        ans=max(ans,last);
        return ans;
    }
};
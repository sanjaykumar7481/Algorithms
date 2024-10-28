class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long max_length=-1;
        unordered_map<long long,int>mp;
        for(auto i:nums)mp[i]=0;
        for(auto i:nums)
        {
            long long c=1,p=i;
            while(mp.find(p*p)!=mp.end() and mp[p*p]==0)
            {
                p*=p;
                mp[p]=1;
                c++;
            }
            max_length=max(c,max_length);
        }
        if(max_length<=1)return -1;
        return max_length;
    }
};
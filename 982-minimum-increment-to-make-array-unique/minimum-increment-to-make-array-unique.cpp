class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums)mp[i]++;
        int p=0,res=0;
        for(auto i:mp)
        {
            if(i.second>1)
            {
                mp[i.first+1]+=i.second-1;
                res+=i.second-1;
                p=i.first+1;
            }
        }
        if(mp[p]>1)
        {
            p-=1;
            res+=(p*(p+1))/2;
        }
        return res;
    }
};
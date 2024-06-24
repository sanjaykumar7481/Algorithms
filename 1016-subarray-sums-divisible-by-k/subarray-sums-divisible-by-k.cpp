class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long s=0;
        int res=0,mod;
        mp[0]=1;
        for(auto i:nums){
            s+=i;
            // if(s%k==0)res++;
            if(s<0)
            {
                int t=abs(s)/k;
                mod=((t+1)*k)+s;
                mod=mod%k;
            }
            else mod=s%k;
            // cout<<mod<<" ";
            if(mp.find(mod)!=mp.end())
            {
                // cout<<mod<<"-"<<i<<" ";
                res+=mp[mod];
            }
            mp[mod]++;
        }
        return res;
    }
};
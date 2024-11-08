class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int pre=0;
        vector<int>res;
        int max=0,num=1<<maximumBit-1;
        while(num)
        {
            num>>=1;
            max++;
        }
        for(auto i:nums)
        {
            pre^=i;
            int ans=0;
            for(int i=0;i<max;i++){
                if((pre&(1<<i))==0)ans|=(1<<i);
            }
            // if(pre&(1<<max)==0)ans|=(1<<max);
            res.push_back(ans);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1,msb=0;
        int temp=n;
        vector<int>bitCount(32,0);
        while(temp)
        {
            temp>>=1;
            msb++;
        }
        int base=(1<<(msb-1)),p=2;
        for(int i=0;i<msb;i++)
        {
            bitCount[i]=((n+1)/p)*(p/2);
            int t=(n+1)%p;
            bitCount[i]+=max(0,t- p/2);
            p*=2;
        }
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int c=0;
            for(auto j:nums)
            {
                if(j&(1<<i))c++;
            }
            if(bitCount[i]<c)ans|=(1<<i);
            // cout<<bitCount[i]<<"-"<<c<<" ";
        }
        return ans;
    }
};
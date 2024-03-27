class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res=0,i=0,j=0;
        long long pro=1;
        while(j<nums.size())
        {
            pro*=nums[j];
            while(i<=j and pro>=k)
            {
                pro/=nums[i++];
            }
            if(j-i>=0)
            {
                res+=1+(j-i);
            }
            // cout<<i<<" "<<j<<" "<<res<<endl;
            j++;
        }
        return res;
    }
};
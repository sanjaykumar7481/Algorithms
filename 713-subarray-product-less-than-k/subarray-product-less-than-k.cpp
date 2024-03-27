class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            long long p=1;
            for(int j=i;j<nums.size();j++)
            {
                p*=nums[j];
                if(p<k)res++;
                else break;
            }
        }
        
        return res;
    }
};
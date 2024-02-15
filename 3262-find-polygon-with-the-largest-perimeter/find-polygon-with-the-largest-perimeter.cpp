class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<long long>prefix(nums.size());
        prefix[0]=nums[0];
        long long ans=-1;
        for(int i=1;i<nums.size();i++)
        {
            if(i-2>=0)
            {
                if(prefix[i-1]>nums[i])
                {
                    ans=max(ans,prefix[i-1]+nums[i]);
                }
            }
            prefix[i]=prefix[i-1]+nums[i];
        }
        return ans;
    }
};
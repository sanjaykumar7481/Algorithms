class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,c=0,res=0,j=0,prev=0,aft=0;
        while(i<nums.size() and c<k)
        {
            if(nums[i]&1)c++;
            i++;
        }
        while(i<nums.size())
        {
            while(nums[j]%2==0 and j<i)
            {
                prev++;
                j++;
            }
            while(i<nums.size() and nums[i]%2==0)
            {
                aft++;
                i++;
            }
            res+=prev+aft+1+(prev*aft);
            j++;
            i++;
            prev=0;
            aft=0;
        }
        while(nums[i-1]&1 and nums[j]%2==0 and j<i-1)
        {
            prev++;
            j++;
        }
        if(nums[i-1]&1)res+=prev+1;
        return res;
    }
};
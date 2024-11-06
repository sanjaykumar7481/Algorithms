class Solution {
public:
    int set_bits(int n)
    {
        int c=0;
        while(n){
            if(n&1)c++;
            n>>=1;
        }
        return c;
    }
    bool canSortArray(vector<int>& nums) {
        int pre=0,len=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(set_bits(nums[i])==set_bits(nums[i+1]))len++;
            else
            {
                sort(nums.begin()+pre,nums.begin()+pre+len);
                len=1;
                pre=i+1;
            }
        }
        sort(nums.begin()+pre,nums.begin()+pre+len);
        for(int i=0;i<nums.size()-1;i++)if(nums[i]>nums[i+1])return false;
        return true;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero=0;
        int i=0,j=0;
        while(j<nums.size())
        {
            if(nums[j]==0)zero++;
            else{
                nums[i]=nums[j];
                i++;
            }
            j++;
        }
        while(i<nums.size() and zero--)
        {
            nums[i]=0;
            i++;
        }
        // return nums;
    }
};
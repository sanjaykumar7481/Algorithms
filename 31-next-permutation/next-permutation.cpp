class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-2;i>=0;i--)
        {
            int k=1e9,ind=-1;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>nums[i])
                {
                    if(k>nums[j])
                    {
                        k=nums[j];
                        ind=j;
                    }
                }
                    
            }
            if(ind!=-1){
                swap(nums[i],nums[ind]);
                sort(nums.begin()+i+1,nums.end());
                return;
            }
        }
        reverse(nums.begin(),nums.end());
    }
};
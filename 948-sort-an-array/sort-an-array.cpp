class Solution {
public:
    void heapify(vector<int>&nums,int i,int n)
    {
        int left=(2*i)+1;
        int right=(2*i)+2;
        int temp=i;
        if(left<n and nums[i]<nums[left])i=left;
        if(right<n and nums[i]<nums[right])i=right;
        if(temp!=i)
        {
            swap(nums[i],nums[temp]);
            heapify(nums,i,n);
        }
    }
    void make_heap(vector<int>&nums)
    {
        for(int i=nums.size()/2;i>=0;i--)heapify(nums,i,nums.size());
    }
    vector<int> sortArray(vector<int>& nums) {
        make_heap(nums);
        // return nums;
        for(int i=nums.size()-1;i>=0;i--)
        {
            swap(nums[i],nums[0]);
            heapify(nums,0,i);
        }
        return nums;
    }
};
class Solution {
public:
    int fun(int i,vector<int>&nums,int s)
    {
        if(i>=nums.size())return s;
        return fun(i+1,nums,s^nums[i])+fun(i+1,nums,s);
    }
    int subsetXORSum(vector<int>& nums) {
        return fun(0,nums,0);
    }
};
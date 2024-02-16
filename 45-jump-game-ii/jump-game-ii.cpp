class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0,c=0;
        if(nums.size()==1)return 0;
        while(i<nums.size())
        {
            int j=i+1,k=nums[i],p=INT_MIN,ind=i+1;
            while(j<nums.size() and k--)
            {
                if(p<=j+nums[j])
                {
                    p=j+nums[j];
                    ind=j;
                }
                j++;
            }
            cout<<ind<<" ";
            i=ind;
            c++;
            if(ind>=nums.size()-1 or j>=nums.size())break;
        }
        return c;
    }
};
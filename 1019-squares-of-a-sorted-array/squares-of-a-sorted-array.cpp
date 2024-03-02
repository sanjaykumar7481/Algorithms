class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>temp,res,temp2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)temp.push_back(nums[i]*nums[i]);
            else temp2.push_back(nums[i]*nums[i]);
        }
        reverse(temp.begin(),temp.end());
        int i=0,j=0;
        while(i<temp.size() and j<temp2.size())
        {
            if(temp[i]<=temp2[j])
            {
                res.push_back(temp[i++]);
            }
            else{
                res.push_back(temp2[j++]);
            }
        }
        while(i<temp.size())res.push_back(temp[i++]);
        while(j<temp2.size())res.push_back(temp2[j++]);
        return res;
    }
};
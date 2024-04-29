class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int a=0,c=0;
        for(auto i:nums)a^=i;
        for(int i=0;i<32;i++)
        {
            if((a&(1<<i))^(k&(1<<i)))c++;
        }
        return c;
    }
};
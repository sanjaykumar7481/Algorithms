class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>arr(201,0);
        for(auto i:nums)
        {
            if(i>=0)arr[i]++;
            else arr[abs(i)+100]++;
        }
        sort(nums.begin(),nums.end(),[&](int &a,int &b){
            int fa=a<0?abs(a)+100:a;
            int fb=b<0?abs(b)+100:b;
            if(arr[fa]<arr[fb])return true;
            else if(arr[fa]==arr[fb])return a>b;
            return false;
        });
        return nums;
    }
};
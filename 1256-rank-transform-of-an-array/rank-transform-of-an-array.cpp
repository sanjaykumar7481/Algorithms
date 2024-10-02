class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>brr=arr;
        sort(arr.begin(),arr.end());
        vector<int>res(arr.size());
        unordered_map<int,int>mp;
        int p=0,i=0;
        while(i<arr.size())
        {
            p++;
            mp[arr[i]]=p;
            i++;
            while(i<arr.size() and arr[i]==arr[i-1])
            {
                mp[arr[i]]=p;
                i++;
            }
        }
        for(int i=0;i<arr.size();i++)res[i]=mp[brr[i]];
        return res;
    }
};
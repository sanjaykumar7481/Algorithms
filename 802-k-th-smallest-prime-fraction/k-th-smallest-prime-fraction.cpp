class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<vector<float>>res;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                res.push_back({(arr[i]/float(arr[j])),float(arr[i]),float(arr[j])});
            }
        }
        sort(res.begin(),res.end());
        k--;
        // return {};
        return {int(res[k][1]),int(res[k][2])};
    }
};
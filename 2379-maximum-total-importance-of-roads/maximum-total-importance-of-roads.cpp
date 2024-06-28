class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        long long res=0;
        for(auto i:roads)
        {
            degree[i[0]]++;
            degree[i[1]]++;
        }
        sort(degree.rbegin(),degree.rend());
        for(auto i:degree)
        {
            res+=(1L*i*n);
            n--;
        }
        return res;
    }
};
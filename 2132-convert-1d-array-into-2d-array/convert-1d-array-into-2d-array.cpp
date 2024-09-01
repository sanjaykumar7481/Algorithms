class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int k=original.size()/n;
        if(k!=m or original.size()%n!=0)return {};
        k=0;
        vector<vector<int>>res(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)res[i][j]=original[k++];
        }
        return res;
    }
};
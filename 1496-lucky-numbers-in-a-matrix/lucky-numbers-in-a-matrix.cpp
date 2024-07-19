class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>res;
        for(int i=0;i<matrix.size();i++)
        {
            int sm=INT_MAX,ind,lr=-1;
            for(int j=0;j<matrix[i].size();j++)
            {
                if(sm>matrix[i][j])
                {
                    sm=matrix[i][j];
                    ind=j;
                }
            }
            for(int k=0;k<matrix.size();k++)
            {
                lr=max(lr,matrix[k][ind]);
            }
            if(lr==sm)res.push_back(lr);
        }
        return res;
    }
};
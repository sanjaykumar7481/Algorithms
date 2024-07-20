class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>>temp(rowSum.size(),vector<int>(colSum.size(),0));
        for(int i=0;i<temp.size();i++)
        {
            for(int j=0;j<temp[0].size() and rowSum[i];j++)
            {
                if(colSum[j]==0)continue;
                int k=min(rowSum[i],colSum[j]);
                temp[i][j]=k;
                rowSum[i]-=k;
                colSum[j]-=k;
            }
        }
        return temp;
    }
};
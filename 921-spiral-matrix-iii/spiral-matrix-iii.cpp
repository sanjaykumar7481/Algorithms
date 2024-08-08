class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>res;
        int count=rows*cols;
        count--;
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        res.push_back({rStart,cStart});
        int p=0,size=1;
        while(count)
        {
            for(int i=0;i<size;i++)
            {
                rStart+=dir[p][0];
                cStart+=dir[p][1];
                if(rStart>=0 and rStart<rows and cStart>=0 and cStart<cols)
                {
                    count--;
                    res.push_back({rStart,cStart});
                }
                if(count==0)return res;
            }
            p=(p+1)%4;
            if(p%2==0)size++;
        }
        return res;
    }
};
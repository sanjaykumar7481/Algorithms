class Solution {
public:
    bool valid(int i,int j,int r,int c)
    {
        if(i<0 or j<0 or i>=r or j>=c)return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size(),columns=heights[0].size();
        vector<vector<int>>dist(rows,vector<int>(columns,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        dist[0][0]=0;
        q.push({0,0,0});
        while(!q.empty())
        {
            auto a=q.top();
            q.pop();
            for(int i=0;i<4;i++)
            {
                if(valid(a[1]+dir[i][0],a[2]+dir[i][1],rows,columns))
                {
                    int effort=abs(heights[a[1]][a[2]]-heights[a[1]+dir[i][0]][a[2]+dir[i][1]]);
                    int final_effort=max(effort,a[0]);
                    if(dist[a[1]+dir[i][0]][a[2]+dir[i][1]]>final_effort)
                    {
                        dist[a[1]+dir[i][0]][a[2]+dir[i][1]]=final_effort;
                        q.push({final_effort,a[1]+dir[i][0],a[2]+dir[i][1]});
                    }
                }
            }
        }
        return dist[rows-1][columns-1];
    }
};
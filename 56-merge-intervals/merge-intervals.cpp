class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        int i=0;
        while(i<intervals.size())
        {
            int j=i+1,lower=intervals[i][0],upper=intervals[i][1];;
            while(j<intervals.size() and upper>=intervals[j][0])
            {
                upper=max(upper,intervals[j][1]);
                j++;
            }
            i=j;
            res.push_back({lower,upper});
        }
        return res;
    }
};
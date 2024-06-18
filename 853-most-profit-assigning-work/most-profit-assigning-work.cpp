class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int res=0;
        for(auto i:worker)
        {
            int p=0;
            for(int j=0;j<profit.size();j++)
            {
                if(difficulty[j]<=i)p=max(p,profit[j]);
            }
            // cout<<p<<" ";
            res+=p;
        }
        return res;
        
    }
};
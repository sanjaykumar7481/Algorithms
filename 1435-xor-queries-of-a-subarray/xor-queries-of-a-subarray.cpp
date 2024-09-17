class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<vector<int>>prefix;
        vector<int>pref(32,0);
        for(int i=0;i<arr.size();i++)
        {
            int num=arr[i],bit=0;
            while(num)
            {
                if(num&1)pref[bit]++;
                num>>=1;
                bit++;
            }
            prefix.push_back(pref);
        }
        vector<int>res;
        for(auto i:queries)
        {
            vector<int>box=prefix[i[1]];
            if(i[0]>0)
            {
                for(int j=0;j<32;j++)
                {
                    box[j]-=prefix[i[0]-1][j];
                }
            }
            int ans=0;
            for(int j=0;j<32;j++)
            {
                if(box[j]&1)ans|=1<<j;
            }
            res.push_back(ans);
        }
        return res;
        
    }
};
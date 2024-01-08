class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<int,int>>subseqVisited(nums.size());
        int ans=0;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                long long  n=(1LL*(nums[i])) - (1LL*(nums[j]));
                // cout<<n<<" ";
                if(n>=INT_MAX or n<=INT_MIN)continue;
                 n=int(n);
                if(subseqVisited[i].find(n)==subseqVisited[i].end())
                        subseqVisited[i][n]=1;
                else subseqVisited[i][n]+=1;
                if(subseqVisited[j].find(n)!=subseqVisited[j].end()){
                    subseqVisited[i][n]+=subseqVisited[j][n];
                    ans+=subseqVisited[j][n];
                }
                
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // vector<int>relative_order(nums.size())
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]=i;
        sort(nums.begin(),nums.end(),[&](int &a,int &b){
            string ta=to_string(a),tb=to_string(b);
            int fa=0,fb=0,p=1;
            for(int i=ta.size()-1;i>=0;i--)
            {
                fa+=mapping[(ta[i]-'0')]*p;
                p*=10;
            }
            p=1;
            for(int i=tb.size()-1;i>=0;i--)
            {
                fb+=mapping[(tb[i]-'0')]*p;
                p*=10;
            }
            // cout<<fa<<" "<<fb<<endl;
            // if(fa!=fb)
                return fa<fb;
            // return mp[a]<mp[b];
        });
        return nums;
    }
};
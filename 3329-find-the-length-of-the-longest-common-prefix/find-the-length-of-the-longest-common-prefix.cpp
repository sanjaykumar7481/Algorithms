class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>mp;
        for(auto i:arr1)
        {
            string k=to_string(i);
            while(k!="")
            {
                mp[k]=0;
                k.pop_back();
            }
        }
        int res=0;
        for(auto i:arr2)
        {
           string k=to_string(i);
            while(res<k.size() and k!="" and mp.find(k)==mp.end())
            {
                k.pop_back();
            }
            if(mp.find(k)!=mp.end())
            {
                if(res<k.size())res=k.size();
            }
        }
        return res;
    }
};
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto i:details)if(i[11]-'0'>6 or (i[11]-'0'==6 and i[12]-'0'>0))ans++;
        return ans;
    }
};
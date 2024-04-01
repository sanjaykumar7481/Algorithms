class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0,res;
        for(auto i:s)
        {
            if(i==' ')
            {
                if(ans)res=ans;
                ans=0;
            }
            else ans++;
        }
        if(ans)res=ans;
        return res;
    }
};
class Solution {
public:
    int minimumLength(string s) {
        int start=0,end=s.size()-1;
        while(start<end and s[start]==s[end])
        {
            if(s[start]==s[end])
            {
                char t=s[start];
                int pre=start;
                while(start<end and s[start]==s[end])start++;
                while(pre<end and s[end]==t)end--;
            }
        }
        // cout<<start<<" "<<end<<endl;
        if(start==end)return 1;
        if(start>end)return 0;
        return end-start+1;
    }
};
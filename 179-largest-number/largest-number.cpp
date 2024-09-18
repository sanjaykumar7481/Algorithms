class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>temp;
        for(auto i:nums)temp.push_back(to_string(i));
        sort(temp.begin(),temp.end(),[&](auto &x,auto &y){
            int i=0;
            auto a=x,b=y;
           for(i=0;i<a.size() and i<b.size() and a[i]==b[i];i++);
            if(i==a.size() or i==b.size())return a+b>b+a;
            return a[i]>b[i];
        });
        string res;
        for(auto i:temp)res+=i;
        if(res[0]=='0')return "0";
        return res;
    }
};
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string newResult;
        int one=0;
        for(auto i:s)if(i=='1')one++;
        for(int i=0;i<s.size()-1;i++)
        {
            if(one-- >1)
            {
                newResult+='1';
            }
            else newResult+='0';
        }
        newResult+='1';
        return newResult;
        
    }
};
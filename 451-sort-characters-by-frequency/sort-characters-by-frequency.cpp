class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,int>>freq(68,{0,0});
        for(auto i:s)
        {
            if(isdigit(i))
            {
                freq[i-'0' +58].first++;
                freq[i-'0' +58].second=i-'0' +58;
                continue;
            }
            freq[i-'A'].first++;
            freq[i-'A'].second=i-'A';
        }
        sort(freq.rbegin(),freq.rend());
        string res;
        for(auto i:freq)
        {
            if(i.first==0)return res;
            while(i.first>0)
            {
                if(i.second>=58)res+=char((i.second-58)+'0');
                else res+=char(i.second+65);
                i.first--;
            }
        }
        return res;
    }
};
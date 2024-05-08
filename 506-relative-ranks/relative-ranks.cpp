class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int,string>mp;
        for(auto i:score)mp[i]="";
        vector<string>temp={"Gold Medal","Silver Medal","Bronze Medal"};
        vector<string>res(score.size());
        int c=1,l=0;
        // mp[mp.begin()->first]="kd";
        for(auto i=mp.rbegin();i!=mp.rend();i++)
        {
            if(l<=2){
                mp[i->first]=temp[l++];
                // cout<<mp[i->first];
            }
            else mp[i->first]=to_string(c);
            c++;
        }
        for(int i=0;i<score.size();i++)
            res[i]=mp[score[i]];
        return res;
    }
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>>res;
        stack<int>st;
        vector<pair<int,int>>temp(positions.size());
        for(int i=0;i<positions.size();i++)temp[i]={positions[i],i};
        sort(temp.begin(),temp.end());
        for(int j=0;j<positions.size();j++)
        {
            int flag=0;
            int i=temp[j].second;
            while(!st.empty() and ((directions[i]=='L' and directions[st.top()]=='R' and positions[i]>positions[st.top()]) or(directions[i]=='R' and directions[st.top()]=='L' and positions[i]<positions[st.top()])) )
            {
                if(healths[i]>healths[st.top()])
                {
                    st.pop();
                    healths[i]--;
                }
                else if(healths[i]==healths[st.top()])
                {
                    st.pop();
                    flag=1;
                    break;
                }
                else{
                    healths[st.top()]--;
                    flag=1;
                    break;
                }
            }
            if(!flag)st.push(i);
        }
        while(!st.empty()){
            res.push_back({st.top(),healths[st.top()]});
            st.pop();
        }
        vector<int>ans;
        sort(res.begin(),res.end());
        for(auto i:res)ans.push_back(i.second);
        return ans;
    }
};
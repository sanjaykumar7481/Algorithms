class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0,n=rating.size();
        vector<pair<int,int>>prev(rating.size());
        prev[0]={0,0};
        set<int>st;
        st.insert(rating[0]);
        for(int i=1;i<rating.size();i++)
        {
            st.insert(rating[i]);
            int c=0;
            for(auto j:st)
            {
                if(j==rating[i])break;
                c++;
            }
            prev[i]={c,st.size()-c-1};
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(rating[j]<rating[i] and prev[j].first)ans+=prev[j].first;
                if(rating[j]>rating[i] and prev[j].second)ans+=prev[j].second;
            }
        }
        return ans;
    }
};